qa_pairs = {
    "hi": "Hello :)",
    "hello": "Hi :)",
    "what is your name": "My name is ChatPP.",
    "who are you": "I'm ChatPP.",
    "how are you": "I'm doing well, thank you!",
    "what can you do": "I can answer your questions, have conversations with you and many more.",
    "goodbye": "Goodbye. "
}

def get_response(user_input):
    for question, answer in qa_pairs.items():
        if user_input.lower() == question.lower():
            return answer
    return "I'm sorry, I don't quite catch that. Could you repeat yourself?"

while True:
    user_input = input("\nYou: ")
    response = get_response(user_input)
    print("niggabot:", response)
    if user_input.lower() == "goodbye":
        break
