import math

filename = "test_5.txt"
test_file = open(filename, mode="w")

a = 12345.67089
b = -2

test_file.writelines(str(a)+'\n')
test_file.writelines(str(b)+'\n')
test_file.writelines(str(a + b)+'\n')
test_file.writelines(str(a - b)+'\n')
test_file.writelines(str(a * b)+'\n')
test_file.writelines(str(a / b)+'\n')
test_file.writelines(str(math.sin(a))+'\n')
test_file.writelines(str(math.sin(b))+'\n')
test_file.writelines(str(math.cos(a))+'\n')
test_file.writelines(str(math.cos(b))+'\n')
test_file.writelines(str(math.log(a))+'\n')
# test_file.writelines(str(math.log(b))+'\n')
# test_file.writelines(str(math.pow(a,b))+'\n')
