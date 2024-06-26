import random

def hang_man(word):
    attemps, maxAttempts, wordToGuess = 0, 7, '_'*len(word)
    
    while attemps<maxAttempts and '_' in wordToGuess:
        print(f"\nWord to guess: {wordToGuess}")
        guess = input('Enter a word: ')
        
        if len(guess)!=1 or not guess.isalpha():
            print("Enter a proper value u dumbass!")
            continue
        
        if guess in word:
            print("You guesses the correct word!")
            for i in range(len(word)):
                if word[i]==guess:
                    wordToGuess = wordToGuess[:i] + guess + wordToGuess[i+1:]
        else:
            print("oops, incorrect guess")
            attemps+=1
            print(f"Number of attemps left: {maxAttempts-attemps-1}") 
            
    if '_' in wordToGuess:
        print(f"You lost, the word was {word}")
    else:
        print(f"You won, the word was {word}")
                   


words = ['apple', 'hello', 'engineering']
word = random.choice(words)
hang_man(word)