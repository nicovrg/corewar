import os
import sys
import filecmp
import subprocess

TGREY = '\033[30m'  # Grey Text
TRED =  '\033[31m' # Red Text
TGREEN =  '\033[32m' # Green Text
TYELLOW =  '\033[33m' # Yellow Text
TCYAN = '\033[36m' # Cyan Text
BPURPLE = '\033[44m' # Purple Background
BYELLOW = '\033[43m' # Yellow Background
BGREEN = '\033[42m' # GREEN Background
BLIGTH_BLUE = '\033[104m' # BLUE Background
TMAGENTA = '\033[35m'
BRED = '\033[41m' # RED Background
ENDC = '\033[m' # reset to the defaults
UP_LINE = '\033[A'
ERASE_LINE = '\033[2K'
BOLD = '\033[1m'

SUCCESS = 0
BOTH_MISSING = 1
BEHAVIORS_DIFFERS = 2
FAILED = 3

os.system('clear')
args = sys.argv
files = []
mode = ""

if (len(args) > 1 and args[1] == "--oneline"):
	args.pop(1)
	mode = "--oneline"

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
		self.file_missing = 0

	def run_test(self):
		if (mode is ""):
			print(BPURPLE + TGREY + '<===== Test Source file : ' + ENDC + BPURPLE + self.file + ENDC + BPURPLE + TGREY + ' =====>' + ENDC)
		elif (mode == "--oneline"):
			print(BOLD + TCYAN + "Testing\t\t"  + self.file.ljust(20, ' ') + ENDC + '\t', end = '')
		self.run_bins()
		if self.file_missing == 0:
			self.cmp_outputs()

	def run_bins(self):
		self.__check_or_create_folders()
		self.__debug_print('\tCompiling with YOUR asm ...')
		os.system(self.path_asm_own + ' src/' + self.file + ' > /dev/null')
		if os.path.isfile('src/' + self.cor_file):
			self.__debug_print('\town .cor is here')
			os.system('mv ' + self.src_cor_file + ' '+ self.out_own_path)
		else:
			self.file_missing += 1
			self.__debug_print('\t' + TYELLOW + 'No OUTPUTS for your ASM buddy' + ENDC + '\n')
		self.__debug_print('\n\tCompiling with 42 asm ...')
		if mode is "":
			cmd = path_asm_model + ' src/' + self.file
		elif mode is "--oneline":
			cmd = path_asm_model + ' src/' + self.file + ' > /dev/null'
		os.system(cmd)
		if os.path.isfile('src/' + '/' + self.cor_file):
			self.__debug_print(UP_LINE + ERASE_LINE)
			self.__debug_print('\t' + UP_LINE + 'model .cor is here\n')
			os.system('mv ' + self.src_cor_file + ' '+ self.out_model_path)
		else:
			self.file_missing += 2
			self.__debug_print('\t' + TYELLOW + 'No OUTPUTS for 42 ASM' + ENDC + '\n')
		if self.file_missing == 3:
			self.__debug_print('\t' + BGREEN + TGREY + '<===== BOTH MISSING =====>' + ENDC + '\n')
			self.__one_line_print('\t' + BOLD + TGREEN + '[SUCCESS]'.ljust(12, ' ') + ENDC + TGREEN + '(both missing)' + ENDC)
			self.result = 1
		elif self.file_missing != 0 and self.file_missing != 3:
			self.__debug_print('\t' + BYELLOW + TGREY + '<===== BEHAVIORS DIFFERS =====>' + ENDC + '\n')
			self.__one_line_print('\t' + BOLD + TRED + '[FAIL]'.ljust(12, ' ') + ENDC + TRED + '(behavior differ)' + ENDC)
			self.result = 2
		
	def cmp_outputs(self):
		diff = filecmp.cmp(self.out_own_path + self.cor_file, self.out_model_path + self.cor_file)
		if diff is True:
			self.__debug_print('\t' + BGREEN + TGREY + '<===== SUCCESS =====>' + ENDC + '\n')
			self.__one_line_print('\t' + BOLD + TGREEN + '[SUCCESS]'.ljust(12, ' ') + ENDC + TGREEN + '(output match)' + ENDC)
			self.result = 0
		else:
			self.__debug_print('\t' + BRED + TGREY + '<===== FAIL =====>' + ENDC + '\n')
			self.__one_line_print('\t' + BOLD + TRED + '[FAIL]'.ljust(12, ' ') + ENDC + TRED + '(output dont match)' + ENDC)
			self.result = 3
			hexa_own = subprocess.check_output('xxd ' + self.out_own_path + self.cor_file, shell=True, universal_newlines=True)
			hexa_model = subprocess.check_output('xxd ' + self.out_model_path + self.cor_file, shell=True, universal_newlines=True)
			hexa_own_lst = list(hexa_own.split('\n'))
			hexa_model_lst = list(hexa_model.split('\n'))
			line_nb = min(len(hexa_model_lst), len(hexa_own_lst))
			i = 0
			while i < line_nb:
				if hexa_own_lst[i] != hexa_model_lst[i]:
					self.__debug_print("Own   :" + hexa_own_lst[i])
					self.__debug_print("Model :" + hexa_model_lst[i])
					self.__debug_print ("Diff at line " + str(i + 1) + " (" + hexa_own_lst[i][:9] + ")" + '\n')
					break
				i = i + 1

	def __check_or_create_folders(self):
		if os.path.isdir("./output") is False:
			os.system("mkdir output")
		if os.path.isdir("./output/own") is False:
			os.system("mkdir output/own")
		if os.path.isdir("./output/model") is False:
			os.system("mkdir output/model")

	def __debug_print(self, string):
		if mode is "":
			print(string)

	def __one_line_print(self, string):
		if mode is "--oneline":
			print(string)

	def get_result(self):
		return self.result

	def clean_outputs(self):
		cmd = 'rm ' + self.out_own_path + '*' + '&&' + 'rm ' + self.out_model_path + '*'
		os.system(cmd)
	

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
		print("\n" + BLIGTH_BLUE + TGREY + '<===== SUMMARY =====>' + ENDC + '\n')
		print("Total files :", self.files_nb)
		print("Success :", self.successes)
		print("Both missing :", self.both_missing)
		print("Behaviors differs :", self.behaviors_diff)
		print("Failed :", self.failed)
	

tests = Run_Test(files)
tests.run()