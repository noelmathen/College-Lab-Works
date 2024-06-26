qa_pairs = {
    "Hi" : "Hello",
    "Hello" : "Hi",
    "How are you" : "I'm fine thanks",
}

def response(userInput):
    for q, a in qa_pairs.items():
        if userInput.lower() == q.lower():
            return a
    return "Sorry, try again"

while True:
    userInput = input("\nYou: ")
    if userInput=="goobei".lower():
        print("Ok bei")
        break
    print(response(userInput))