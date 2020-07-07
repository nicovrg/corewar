import os
import sys
import filecmp
import subprocess

TGREY = '\033[30m'  # Grey Text
TRED =  '\033[31m' # Red Text
TGREEN =  '\033[32m' # Green Text
TYELLOW =  '\033[33m' # Yellow Text
BPURPLE = '\033[44m' # Purple Background
BYELLOW = '\033[43m' # Yellow Background
BGREEN = '\033[42m' # GREEN Background
BLIGTH_BLUE = '\033[104m' # GREEN Background
BRED = '\033[41m' # RED Background
ENDC = '\033[m' # reset to the defaults

SUCCESS = 0
BOTH_MISSING = 1
BEHAVIORS_DIFFERS = 2
FAILED = 3


os.system('clear')
args = sys.argv
files = []
if len(args) > 1:
	args.pop(0)
	for arg in args:
		files = files + [arg + '.s']
else:
	files = os.listdir('./src')

path_asm_own = './asm_own'
path_asm_model = './asm_model'
out_own_path = 'output/own/'
out_model_path = 'output/model/'

class Test:
	def __init__(self, file, path_asm_own, path_asm_model, out_own_path, out_model_path):
		self.file = file
		self.cor_file = file[:-1] + 'cor'
		self.src_cor_file = 'src/' + self.cor_file
		self.path_asm_own = path_asm_own
		self.path_asm_model = path_asm_model
		self.out_own_path = out_own_path
		self.out_model_path = out_model_path
		self.result = -1

	def run_test(self):
		print(BPURPLE + TGREY + '<===== Test Source file : ' + ENDC + BPURPLE + self.file + ENDC + BPURPLE + TGREY + ' =====>' + ENDC + '\n')
		if self.run_bins() == 0:
			self.cmp_outputs()

	def __check_or_create_folders(self):
		if os.path.isdir("./output") is False:
			os.system("mkdir output")
		if os.path.isdir("./output/own") is False:
			os.system("mkdir output/own")
		if os.path.isdir("./output/model") is False:
			os.system("mkdir output/model")
		
	def run_bins(self):
		file_missing = 0
		self.__check_or_create_folders()
		print('\tCompiling with YOUR asm ...')
		cmd = self.path_asm_own + ' src/' + self.file + ' > /dev/null'
		os.system(cmd)
		if os.path.isfile('src/' + self.cor_file):
			print('\town .cor is here')
			os.system('mv ' + self.src_cor_file + ' '+ self.out_own_path)
		else:
			file_missing = file_missing + 1
			self.file_missing = 1
			print('\t' + TYELLOW + 'No OUTPUTS for your ASM buddy' + ENDC + '\n')
		
		print('\n\tCompiling with 42 asm ...')
		cmd = path_asm_model + ' src/' + self.file
		os.system(cmd)
		if os.path.isfile('src/' + '/' + self.cor_file):
			print('\033[A\033[2K')
			print('\t\033[Amodel .cor is here\n')
			os.system('mv ' + self.src_cor_file + ' '+ self.out_model_path)
		else:
			file_missing = file_missing + 2
			print('\t' + TYELLOW + 'No OUTPUTS for 42 ASM' + ENDC + '\n')
			
		if file_missing == 3:
			print('\t' + BGREEN + TGREY + '<===== BOTH MISSING =====>' + ENDC + '\n')
			self.result = 1
		elif file_missing != 0 and file_missing != 3:
			print('\t' + BYELLOW + TGREY + '<===== BEHAVIORS DIFFERS =====>' + ENDC + '\n')
			self.result = 2

		
		return file_missing
	
	def cmp_outputs(self):
		diff = filecmp.cmp(self.out_own_path + self.cor_file, self.out_model_path + self.cor_file)
		if diff is True:
			print('\t' + BGREEN + TGREY + '<===== SUCCESS =====>' + ENDC + '\n')
			self.result = 0
		else:
			print('\t' + BRED + TGREY + '<===== FAIL =====>' + ENDC + '\n')
			self.result = 3
			hexa_own = subprocess.check_output('xxd ' + self.out_own_path + self.cor_file, shell=True, universal_newlines=True)
			hexa_model = subprocess.check_output('xxd ' + self.out_model_path + self.cor_file, shell=True, universal_newlines=True)
			hexa_own_lst = list(hexa_own.split('\n'))
			hexa_model_lst = list(hexa_model.split('\n'))
			line_nb = min(len(hexa_model_lst), len(hexa_own_lst))
			i = 0
			while i < line_nb:
				if hexa_own_lst[i] != hexa_model_lst[i]:
					print("Own   :" + hexa_own_lst[i])
					print("Model :" + hexa_model_lst[i])
					print ("Diff at line " + str(i + 1) + " (" + hexa_own_lst[i][:9] + ")" + '\n')
					break
				i = i + 1
	
	def clean_outputs(self):
		cmd = 'rm ' + self.out_own_path + '*' + '&&' + 'rm ' + self.out_model_path + '*'
		os.system(cmd)

	def get_result(self):
		return self.result

class Run_Test:	
	def __init__(self, lst_files):
		self.files = lst_files
		self.lst_tests = []
		self.files_nb = len(lst_files)
		self.successes = 0
		self.both_missing = 0
		self.behaviors_diff = 0
		self.failed = 0
	
	def run(self):
		self.create_lst_tests()
		self.run_tests()
		self.count_results()
		self.print_results()

	def create_lst_tests(self):
		for file in self.files:
			self.tmp_test = Test(file, path_asm_own, path_asm_model, out_own_path, out_model_path)
			self.lst_tests.append(self.tmp_test)

	def run_tests(self):
		for test in self.lst_tests:
			test.run_test()

	def count_results(self):
		current_res = 0
		for test in self.lst_tests:
			current_res = test.get_result()
			if current_res is SUCCESS:
				self.successes += 1
			if current_res is BOTH_MISSING:
				self.both_missing += 1
			if current_res is BEHAVIORS_DIFFERS:
				self.behaviors_diff += 1
			if current_res is FAILED:
				self.failed += 1

	def print_results(self):
		print(BLIGTH_BLUE + TGREY + '<===== SUMMARY =====>' + ENDC + '\n')
		print("Total files :", self.files_nb)
		print("Success :", self.successes)
		print("Both missing :", self.both_missing)
		print("Behaviors differs :", self.behaviors_diff)
		print("Failed :", self.failed)
		
tests = Run_Test(files)
tests.run()