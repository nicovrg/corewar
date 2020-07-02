import filecmp
import os
import subprocess

TGREY = '\033[30m'  # Grey Text
TRED =  '\033[31m' # Red Text
TGREEN =  '\033[32m' # Green Text
TYELLOW =  '\033[33m' # Yellow Text
BPURPLE = '\033[45m' # Purple Background
ENDC = '\033[m' # reset to the defaults


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
		self.diff = bool

	def run_test(self):
		print(BPURPLE + TGREY + '<===== Test Source file : ' + ENDC + BPURPLE + file + ENDC + BPURPLE + TGREY + ' =====>' + ENDC + '\n')
		if self.run_bins() == 0:
			self.cmp_outputs()
		print("<==============================>\n\n")
		
	def run_bins(self):
		file_missing = 0
		print('\tCompiling with YOUR asm ...')
		cmd = self.path_asm_own + ' src/' + self.file + ' > /dev/null'
		os.system(cmd)
		if os.path.isfile('src/' + self.cor_file):
			print('\town .cor is here')
			os.system('mv ' + self.src_cor_file + ' '+ self.out_own_path)
		else:
			file_missing = 1
			print(TYELLOW + 'No OUTPUTS for your ASM buddy' + ENDC)
		
		print('\n\tCompiling with 42 asm ...')
		cmd = path_asm_model + ' src/' + file
		os.system(cmd)
		if os.path.isfile('src/' + '/' + self.cor_file):
			print('\033[A\033[2K')
			print('\t\033[Amodel .cor is here\n')
			os.system('mv ' + self.src_cor_file + ' '+ self.out_model_path)
		else:
			file_missing = 2
			print(TYELLOW + 'No OUTPUTS for 42 ASM' + ENDC)
		return file_missing

	
	def cmp_outputs(self):
		diff = filecmp.cmp(self.out_own_path + self.cor_file, self.out_model_path + self.cor_file)
		if diff is True:
			print(TGREEN + '||||| <' + self.file + '> SUCCESS |||||' + ENDC)
		else:
			print(TRED + '||||| <' + self.file + '> FAILED |||||' + ENDC)
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
					print ("Diff at line " + str(i + 1) + " (" + hexa_own_lst[i][:9] + ")")
					break
				i = i + 1

			
	
	def clean_outputs(self):
		cmd = 'rm ' + self.out_own_path + '*'
		os.system(cmd)
		cmd = 'rm ' + self.out_model_path + '*'
		os.system(cmd)
		# print(cmd)

os.system('clear')
test_lst = []
for file in files:
	tmp_test = Test(file, path_asm_own, path_asm_model, out_own_path, out_model_path)
	test_lst.append(tmp_test)
	tmp_test.run_test()
# tmp_test.clean_outputs()

	




	# os.system('rm ' cor_file)
# test = filecmp.cmp('output/own/test.cor', 'output/model/test.cor')
# print (files)
# if test:
# 	print(test)
# else:
# 	print("fwefew")