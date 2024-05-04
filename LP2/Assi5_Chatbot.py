import random

class ChatBot:

    def __init__(self):

        # Dictionary of intents mapped with keywords
        self.intents = {
            "welcome": ["hello", "hi", "hey"],
            "order": ["order", "place an order", "buy", "purchase"],
            "menu": ["menu", "dish", "food", "meal", "items", "pizza", "serve"],
            "hours": ["hours", "time", "open", "close", "timing", "schedule"],
            "location": ["location", "address", "where are you", "direction", "map"],
            "contact": ["contact", "phone", "email", "reach out", "contact us", "get in touch"],
            "exit": ["exit", "bye", "quit", "goodbye"],
            "ok": ["ok", "okay", "alright"],
            "thanks": ["thanks", "thank", "appreciate", "thank you"]
        }

        # Dictionary of intents mapped with responses
        self.responses = {
            "menu": ["Our menu includes Margherita, Pepperoni, Hawaiian, and Veggie pizzas. What would you like to order?",
                    "We offer a variety of pizzas including Margherita, Pepperoni, Hawaiian, and Veggie. What can I assist you with?"],
            "order": ["To place an order, you can visit our website or call us at 123-456-7890. How can I help you further?",
                    "You can place your order online through our website or give us a call at 123-456-7890. What else would you like to know?"],
            "hours": ["We are open from 11:00 AM to 10:00 PM from Monday to Sunday. How can I assist you further?",
                    "Our restaurant hours are from 11:00 AM to 10:00 PM every day of the week. What else would you like to know?"],
            "location": ["We are located at 123 Main Street, City, State, ZIP. How can I help you further?",
                        "Our restaurant is situated at 123 Main Street. What else would you like to know?"],
            "contact": ["You can contact us at 123-456-7890 or email us at info@example.com. How can I assist you further?",
                        "Feel free to reach out to us at 123-456-7890 or via email at info@example.com. What else would you like to know?"],
            "default": ["I'm sorry, I didn't quite get that. Can you please rephrase your question?",
                        "I'm not sure I understand. Could you ask again in a different way?"],
            "welcome": ["Hello! Welcome to PizzaBot. How can I assist you today?","Hi there! Welcome to PizzaBot. How can I help you today?",
                        "Hey! Welcome to PizzaBot. What can I do for you today?"],
            "exit": ["Goodbye! Thank you for visiting PizzaBot. Have a great day!","Goodbye! Hope to see you again soon. Have a wonderful day!",
                     "Bye! Thanks for chatting with PizzaBot. Take care!"],
            "thanks": ["You're welcome! If you need any further assistance, feel free to ask.", "No problem! Let me know if there's anything else I can help you with.",
                       "Glad I could assist you! If you have any more questions, just ask."],
            "ok": ["Alright! Let me know if there's anything else I can do for you.","Got it! Feel free to ask if you need any further information.",
                   "Sure thing! If you have any other questions, don't hesitate to ask."],
        }

    def is_in_userquery(self, keywords: list[str], user_query: str) -> bool:

        """
        Check if the any of the givem keywords occur in user_query

        parameters:
        - keywords: list of keywords
        - user_query: user query string
        """

        for word in keywords:
            if word in user_query:
                return True
        return False

    def get_response(self, user_query) -> str:

        """
        Generate response for the given user query

        parameters:
        - user_query: user query string
        """

        user_query = user_query.lower()
        for intent, keywords in self.intents.items():
            if self.is_in_userquery(keywords=keywords, user_query=user_query):
                return random.choice(self.responses[intent])
        return random.choice(self.responses["default"])
    
    def chat(self) -> None:

        """
        Function to chat with the chatboat
        """

        print(random.choice(self.responses["welcome"]))
        while True:
            user_query = input("You: ")
            if self.is_in_userquery(self.intents["exit"], user_query):
                print(random.choice(self.responses["exit"]))
                break
            response = self.get_response(user_query)
            print("PizzaBot: ", response)

def main():
    chat_bot = ChatBot()
    chat_bot.chat()

main()