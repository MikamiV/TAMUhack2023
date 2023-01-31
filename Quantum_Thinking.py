from sympy import*
from numpy import*
import time
import matplotlib.pyplot
print()
print("This program is designed to show the probability of the user having quantum thoughts or binary thoughts.")
print("A score system will give a maximum of one point for each question given the \"Correct\" answer")
print()

points = 0
print("Part One: This section is designed for the inputter to decide the\n"
      "\"Most correct answer\" on a scale -10 to 10.")
print()
print("In this case two options will be given and -10 would be full commitment to option 1\n"
      "and 10 would be full commitment to option 2.")
print()
print("Which option is more correct? (Valid inputs are whole numbers between -10 and 10.)")
print("(-10)--|--|--|--|--|--|--|--|--|--(0)--|--|--|--|--|--|--|--|--|--(10)  ")
#Q1
while True:
    try:
        points += (10 - abs(double(input("Question 1: Chips or Salsa?: ")))) / 10
    except ValueError:
        print("Try again, invalid input.")
        print()
    else:
        break

print()
#Q2
while True:
    try:
        points += (10 - abs(double(input("Question 2: Red or Purple?: ")))) / 10
    except ValueError:
        print("Try again, invalid input.")
        print()
    else:
        break

print()
#Q3
while True:
    try:
        points += (10 - abs(double(input("Question 3: Which one: the city or countryside?: ")))) / 10
    except ValueError:
        print("Try again, invalid input.")
        print()
    else:
        break

print()
#Q4
while True:
    try:
        points += (10 - abs(double(input("Question 4: Is it better to be individual or part of a group?: ")))) / 10
    except ValueError:
        print("Try again, invalid input.")
        print()
    else:
        break

print()
#Q5
while True:
    try:
        points += (10 - abs(double(input("Question 5: Is it better to be logical or emotional?: ")))) / 10
    except ValueError:
        print("Try again, invalid input.")
        print()
    else:
        break

print()
#Q6
while True:
    try:
        points += (10 - abs(double(input("Question 6: It is better to be more practical or idealistic?: ")))) / 10
    except ValueError:
        print("Try again, invalid input.")
        print()
    else:
        break

print()
#Q7
while True:
    try:
        points += (10 - abs(double(input("Question 7: Is it more important to be right or to understand?: ")))) / 10
    except ValueError:
        print("Try again, invalid input.")
        print()
    else:
        break

print()
#Q8
while True:
    try:
        points += (10 - abs(double(input("Question 8: Is it better to have certainty or to have ambiguity?: ")))) / 10
    except ValueError:
        print("Try again, invalid input.")
        print()
    else:
        break

print()
#Q9
while True:
    try:
        points += (10 - abs(double(input("Question 9: Progress is always good or has negative consequences?: ")))) / 10
    except ValueError:
        print("Try again, invalid input.")
        print()
    else:
        break

print()
#Q10
while True:
    try:
        points += (10 - abs(double(input("Question 10: Is it better to live a long life or to live a meaningful life?: ")))) / 10
    except ValueError:
        print("Try again, invalid input.")
        print()
    else:
        break

print()

print()
print()

print("Part Two: This section is designed for the inputter to decide the\n"
      "\"Most correct answer\" based on two strict options. Time is a variable in this section.")
print()
print("Input either any single phrase/word answer responding to the question:")
print()

#Starter question not meant to have time accounted for
questionOne = input("The sky is blue (T/F): ")
print()

#Code for the second timed question
#This portion uses the time package to measure time taken between answering questions
startTime = time.time()
questionTwo = input("Is the glass half full or half empty?: ")
endTime = time.time()
elapsedTime = endTime - startTime

if (elapsedTime >= 7):
    points += 1

else:
    points += elapsedTime/7

print()

#3rd
startTime = time.time()
questionFour = input("When given the option to choose between two identical doors next to each other,\n"
                     "which do you choose, the left door or right one?: ")
endTime = time.time()
elapsedTime = endTime - startTime

if (elapsedTime >= 10):
    points += 1

else:
    points += elapsedTime/10

print()

#4th timed question
startTime = time.time()
questionFour = input("Is infinity is existent or nonexistent?: ")
endTime = time.time()
elapsedTime = endTime - startTime

if (elapsedTime >= 15):
    points += 1

else:
    points += elapsedTime/15

print()

#5th
startTime = time.time()
questionFive = input("If everything is relative, is relative to what?: ")
endTime = time.time()
elapsedTime = endTime - startTime

if (elapsedTime >= 25):
    points += 1

else:
    points += elapsedTime/25

print()
#Final
startTime = time.time()
questionSix = input("Can something both exist and not exist at the same time?: ")
endTime = time.time()
elapsedTime = endTime - startTime

if (elapsedTime >= 12):
    points += 1

else:
    points += elapsedTime/12


totalPoints = int((points/15)* 100)

if (totalPoints > 50):
    print("You are", totalPoints, "% a quantum thinker.")

if (totalPoints < 50):
    print("You are", totalPoints, "% a binary thinker.")

if (totalPoints == 50):
    print("You are coexisting in two states at once between binary and quantum thinking and scored\n",
          totalPoints, "%")

