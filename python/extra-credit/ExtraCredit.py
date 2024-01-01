#PYTHON BASICS AND MATH OPERATIONS
    #1. user age in days

date = input("enter today's date in MM/DD/YYYY format: ")
#split the date
date = date.split("/")
#find the date
currentYear = int(date[2])
currentMonth = int(date[0])
currentDay = int(date[1])

#find user's bday
userBday = input("enter your birthday in MM/DD/YYYY format: ")
#split up bday
userBday = userBday.split("/")
#find the bday
bdayYear = int(userBday[2])
bdayMonth = int(userBday[0])
bdayDay = int(userBday[1])

#convert age in years into days
years = (currentYear - bdayYear) * 365
#convert age in months into days
months = (currentMonth - bdayMonth) * 31 
#find age in days
days = currentDay - bdayDay

#find overall age in days
age = years + months + days
print("you are",age,"days old")


#CONDITIONALS
    #1. 24hr conversion

#ask user for the hour
hour = int(input("enter an hour value from 0 - 23: "))
#if hour is between 1 AM and 11 AM
if hour > 0 and hour < 12:
    #no conversion is needed
    print(hour,"AM")
#it is 12 AM
elif hour == 0:
    print("12 AM")
#it is 12 PM
elif hour == 12:
    print("12 PM")
#it is between 1 PM and 11 PM
elif hour > 12 and hour <= 23:
    #time must by subtracted by 12 
    print((hour - 12),"PM")
else:
    print('was not an option')


    #2. 2 integer inputs 

#ask user for two int inputs 
intOne = int(input("enter an integer input: "))
intTwo = int(input("enter another integer input: "))
#ask user to add or subtract the ints
choice = input("would you like to add or multiply the integers? ")
choice = choice.lower()
#user chose to add the ints
if choice == "add":
    answer = intOne + intTwo
#user chose to multiply the ints
elif choice == "multiply":
    answer = intOne * intTwo
else:
    print("was not an option")
print(answer)
#ints are the same
if intOne == intTwo:
    print("same")
#ints are different
else:
    print("different")


    #. BMI calc

#ask user for their height and weight 
height = int(input("enter your height in inches: "))
weight = int(input("enter your weight in lbs: "))
#find the BMI
bmi = (weight/(height**2)) * 703

#find the BMI index
#user is underweight
if bmi < 18.5:
    print("you are underweight, your BMI is:",bmi)
#user is normal
elif bmi >= 18.5 and bmi < 25:
    print("you are at a normal weight, your BMI is:",bmi)
#user is overweight 
elif bmi >= 25 and bmi < 30:
    print("you are overweight, your BMI is:",bmi)
#user is obese
else:
    print("you are obese, your BMI is:",bmi)


#STRINGS
    #1. first 10 nums divisible by 3 
#stop printing after the 10th num
numCount = 0
#start counting from 1
num = int(1)
while numCount != 10:
    if num % 3 == 0:
        print(num)
        numCount += 1
    num += 1


    #2. 2 sums and print sum

#ask user for 2 nums
#set ask count to 0 for the while loop
askCount = 0
#break out of loop if user has input numbers more than 3 times
while askCount < 3:
    #ask user to input 2 nums
    numOne = int(input("enter a num: "))
    numTwo = int(input("enter another num: "))
    #find the sum of nums
    sum = numOne + numTwo
    #if sum = 0, increase ask count by 1
    if sum == 0:
        askCount += 1
    #the sum is not equal to 0
    else:
        askCount = 4
    print(sum)
#the user broke out of the loop by increasing the ask count too many times
if askCount == 3:
    print("goodbye")

    #3. print remaining alphabet letters 

#ask user for a letter in the alphabet
letter = input("enter a lowercase letter: ")
#define the alphabet
alphabet = "abcdefghijklmnopqrstuvwxyz"
#find the remaining alphabet after the input letter
remainingAlphabet = alphabet.split(letter)
#use only index 1 of the remaining alphabet and turn it into a list
remainingAlphabet = list(remainingAlphabet[1])
remainingAlphabet.insert(0,letter)
print(remainingAlphabet)

    #4. vowel or consonant heavy

#define the vowels
vowels = "aeiou"
#find how many vowels occur in the input
vowelCount = 0
#ask user for a string input
strInput = input("enter a string: ")
#find the number of vowels in the string
for letter in strInput:
    for vowel in vowels:
        if letter == vowel:
            vowelCount += 1

#there are 3 or more vowels in the string
if vowelCount >= 3:
    print("vowel heavy!")
#there are less than 3 vowels in the string
else:
    print("consonant heavy!")

#FUNCTIONS
    #1. reverse uppercase string

def reverseUpper(str):
    #make the string uppercase
    str = str.upper()
    #find the reverse of the uppercase string
    reverseUpperStr = str[::-1]
    return reverseUpperStr

#ask the user to input a string
strInput = input("enter a string: ")
print(reverseUpper(strInput))


    #2. recursion 

def factorial(num):
    if num == 1 or num == 0:
        return 1
    else:
        return(num * factorial(num - 1))

number = int(input("enter a number: "))
print("the factorial of",number,"is",factorial(number))


    #3. function min

def minimum(x,y,z):
    #find the minimum of the three ints
    return min(x,y,z)

#ask user for 3 int inputs
intOne = int(input("enter an int: "))
intTwo = int(input("enter another int: "))
intThree = int(input("enter another int: "))
print(minimum(intOne,intTwo,intThree))


    #4. lower and uppercase counter  

def counter(str):
    #lower and uppercase counters start at 0
    lower = 0
    upper = 0
    #count the num of lower and uppercase letters in str
    for char in str:
        if char.islower() == True:
            lower += 1
        if char.isupper() == True:
            upper += 1
    print(lower,"lowercase letters and",upper,"uppercase letters")

#ask user to input a string
strInput = input("enter a string: ")
#calls the function
counter(strInput)


    #5. hello world

#returns hello
def a():
    return "hello"
#returns world
def b():
    return "world"
#returns hello world
def c():
    print(a(),b())

#call the function c()
c()


#LISTS
    #1. return list of string

#ask user for a string
strInput = input("enter a string: ")
#convert string into a list
strList = list(strInput)
print(strList)


    #2. add string of nums ***********

#ask user for a string of nums
numStr = (input("enter a string of nums: "))
#convert to a list
strList = list(numStr)
#convert to a list of ints
intList = list(map(int,strList))
#find and print the sum
print("the sum is",sum(intList))

#set product equal to 1 for multiplacation
product = 1
    #iterate through the list
for num in intList:
    product = num * product 
print("the product is",product)


    #3. list of all nums divisibly by 7 under 100 

#create a list
listA = []
#find the numbers divisible by 7 under 100
for num in range(1,100):
    if num % 7 == 0:
        #add the nums to the end of listA
        listA.append(num)   
print(listA)

    #4. nums belonging to both list 

listA = [1,2,3,4,5,6]
listB = [4,5,6,7,8]
#create a seperate list to find common nums
listC = []
for i in listA:
    for j in listB:
        #if num is common
        if i == j:
            #append num to listC
            listC.append(i)
print(listC)

    #5. square of list A

listA = [1,2,3,4,5,6]
listB = []
for num in listA:
    #find the square of the nums in listA
    listB.append(num**2)
#reverse the order of the list
print(listB[::-1])

    #6. pascal's triangle 

#create a function for the factorial
def factorial(num):
    if num == 1 or num == 0:
        return 1
    else:
        return(num * factorial(num - 1))

#ask user for the height of the triangle
height = int(input("enter the height of the triangle: "))

for i in range(height):
    for j in range(height-i+1):
        # for left spacing
        print(end=" ")
 
    for j in range(i+1):
        #equation
        print(factorial(i)//(factorial(j)*factorial(i-j)),end=" ")
    # for new line
    print()
