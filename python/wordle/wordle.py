import random

#open the words.txt file 
with open("words.txt") as file:
    #get the word options for the wordle
    wordOptions = [s.strip() for s in file.readlines()]

#print the instructions
def printInstructions():
    return "Enter a five letter word"

#get a random word
def getRandomWord():
    return random.choice(wordOptions)

#check if the user input is a valid word 
def readInput():
    #set isValid is false for the while loop
    isValid = False
    #while the guess in not valid
    while isValid == False: 
        #ask the user to inputnb  a guess
        guess = input("Enter a valid word: ").lower()
        #make sure the guess only includes letters
        if guess.isalpha == False or len(guess) != 5:
            isValid = False
        #if the guess is in the word options the guess is valid
        elif guess in wordOptions:
            isValid = True
    return guess
            
#call the function to print the instructions
printInstructions()
#call the function to get a random word
word = getRandomWord()
#counts the number of times a guess is made
guessNum = 0
#set guess as "" for the while loop
guess = ""

while guessNum < 6 and word != guess:
    #ask user for a guess
    guess = readInput()
    #used to iterate through the guess and word
    for i in range(0,5):
        #if letter in guess and word are in the same place
        if guess[i] == word[i]:
            print(guess[i],"is correct")
        #if guess and word share a letter
        elif guess[i] in word:
            print(guess[i],"is in the wrong spot")
        #if the letter in not in the word
        else:
            print(guess[i],"is not in the word")

    #print the letters that have not yet been used
    print("the remaining letters are:", end=" ")
    #from range a - z
    for i in range(97,123):
        if chr(i) not in guess:
            print(chr(i), end=" ")
    print()

    guessNum += 1

#if you have guessed the word
if guess == word:
    print("You won!")
#if you have exceeded the number or guesses allowed
else:
    print("You failed, the word was:",word)

