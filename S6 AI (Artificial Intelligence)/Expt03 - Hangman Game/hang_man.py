import random

def hangman(word):
    maxAttempts = 7
    attempts = 0
    wordToGuess = '_' * len(word)
    
    while attempts<maxAttempts and '_' in wordToGuess:
        print('\nWord to guess: '+wordToGuess)
        guess = input('Guess a character: ').lower()
        
        if len(guess)!=1 or not guess.isalpha():
            print("Please enter a single alphabetic character.")
            continue
        
        if guess in word:
            print('Correct Guess!')
            for i in range(len(word)):
                if word[i]==guess:
                    wordToGuess = wordToGuess[:i] + guess + wordToGuess[i+1:]
        else:
            print('Incorrect Guess!') 
            if maxAttempts-attempts-1 > 0:
                print('Number of wrong attempts left: '+str(maxAttempts-attempts-1))  
            attempts += 1     
        
    if '_'  not in wordToGuess:
        print('\nCongratz! You guessed the word correctly! The word is: '+word)
    else:
        print('\nSorry:( You didny guess the word correctly! The word was: '+word)
        
print('NOTE: Maximum of 7 wrong attempts are only allowed')
words = ['noel', 'mathen', 'eldho']
word=random.choice(words)
hangman(word)
