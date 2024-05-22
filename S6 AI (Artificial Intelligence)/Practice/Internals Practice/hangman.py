import random

def hangman(word):
    maxAttempts, attempts, wordToGuess = 7, 0, '_'*len(word)
    
    while attempts<maxAttempts and '_' in wordToGuess:
        print('\nWord to guess is: '+(wordToGuess))
        guess = input('Enter the guess: ').lower()
        
        if len(guess)!=1 or not guess.isalpha():
            print('Error in input!')
            
        if guess in word:
            print('Correct guess!')
            for i in range(len(word)):
                if guess==word[i]:
                    wordToGuess = wordToGuess[:i]+guess+wordToGuess[i+1:]
        else:
            print('Incorrect guess')
            if maxAttempts-attempts-1 > 0:
                print(f'Only {maxAttempts-attempts-1} attempts left')
            attempts+=1

words = ['rajagiri', 'engineering', 'noel', 'mathen', 'eldho']
word = random.choice(words)
hangman(word)