#based on python3.6  
print("---guess four numbers---")  
import string
import random  
ran0 = random.randint(0,9)  
ran1 = random.randint(0,9)  
ran2 = random.randint(0,9)  
ran3 = random.randint(0,9)  
ranFour = [ran0,ran1,ran2,ran3]
inpFour = []  
#numFour = input ('Please_input_four_numbers,each_one_from_0_to_9,seperate_them_with_space,press_enter_to_finish_input\(Please_only_input_4_numbers,_otherwise_the_input_is_invalid.)_\n:')  

numFour = raw_input("Please input four numbers, seperate them with space, press enter to finish input.\n:")
#numFour = input ('blabla')
inpFour = numFour.split(' ')  
num0 = int(inpFour[0])
num1 = int(inpFour[1])
num2 = int(inpFour[2])
num3 = int(inpFour[3])
inpFour = [num0,num1,num2,num3]  
print("your input are:",num0,num1,num2,num3)  
print("the randomly generated numbers are:",ran0,ran1,ran2,ran3)  
#guess the right number(gtrn)  
#guess the number of right numbers(n)  
gtrn = []  
if (num0 == ran0) and (num1 == ran1) and (num2 == ran2) and (num3 == ran3):
    print("OK!!(four numbers and sequence are all correct!)")  
else:
    for x in ranFour:  
        if x in inpFour:  
            gtrn.append(x)  
    n =  len(gtrn)  
    if n == 0:  
        print("none of the numbers is correct.")  
    elif n == 1:  
        print("one number is correct: ",gtrn)  
    elif n == 2:  
        print("two numbers are correct: ",gtrn)  
    elif n == 3:  
        print("three numbers are correct: ",gtrn)  
    elif n == 4:  
        print("four numbers are correct: ",gtrn)  
