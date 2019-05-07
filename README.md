#Mastermind
In this task we wrote the Mastermind game, but in a different version.
The guesser - in our project called 'smart guesser' - chooses a series of numbers between 0-9 with repetition, at most 4 length, in less then 100 turns.
Our algorithm does it in maximum 34 turns (depends on the length), and in general, 
if the length is n, it does it in n! + 10. Not very efficient, but does the work.
It works like this: 
1. Try all options 0000, 1111, untill 9999 (according to the length).
2. Learn what are the numbers and the amount of them in the function learn() and saveResults().
3. Calculate all permutations of the numbers and add them to guessVec in the funcion permute().
4. return one string at a time from guessVec untill you get the right one.
Submitted by Oranit Cohen, and Karin Aharon.
