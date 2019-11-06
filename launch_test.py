import subprocess
import os

with os.scandir('test_expected_output/') as entries:
	for entry in entries:
		process = subprocess.Popen(['./exsys', 'test_data/' + entry.name], stdout=subprocess.PIPE)
		output = process.stdout.read().decode('ascii')
		with open('test_expected_output/' + entry.name, 'r') as f:
			expected = f.read()
		if output != expected:
			print('Error for file ' + entry.name)
			print('--- Expected ---')
			print(expected)
			print('--- Got ---')
			print(output)
		else:
			print(entry.name + ' : OK')
