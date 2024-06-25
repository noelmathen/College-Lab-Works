import random

def hang_man(word):
    maxAttempts, attemps, wordToGuess = 7, 0, '_'*len(word)
    while attemps<maxAttempts and '_' in wordToGuess:
        print(f"\nWord to guess: {wordToGuess}")
        guess = input('Enter an alphabet: ').lower()
        
        if len(guess)!=1 or not guess.isalpha():
            print("Enter a PROPER word dumbass!")
            continue
        
        if guess in word:
            print("Correct Guess!")
            for i in range(len(word)):
                if word[i]==guess:
                    wordToGuess = wordToGuess[:i] + guess + wordToGuess[i+1:]
        
        else:
            print("Incorrect guess!")
            print(f"Number of attempts left: {maxAttempts-attemps-1}")
            attemps+=1
    
    if '_' in wordToGuess:
        print(f"\nSorry, you ran out of attemps. the correct word is: {word}")
    else:
        print(f"\nCongratz! You guess the word right! The word is: {word}")

words = ['noel', 'mathen', 'eldho']
word = random.choice(words)
hang_man(word)