# AI Chatbot Using Recurrent Neural Networks (RNN)
## Overview
This project is an AI chatbot designed to provide real-time responses to user inputs. It leverages text preprocessing techniques and a Recurrent Neural Network (RNN) model to understand and generate relevant replies. The chatbot is integrated into a web-based GUI using Flask, offering users a seamless interaction experience.

## Features
- Text Preprocessing: User inputs are tokenized, lemmatized, and converted into a bag-of-words format to standardize and simplify the text. This ensures that the model understands the input effectively.
- RNN Model: The chatbot is powered by a Recurrent Neural Network, which learns from patterns in the data and generates accurate responses based on the user’s input.
- Real-time Interaction: The chatbot responds to user queries in real-time, making the interaction dynamic and engaging.
- Flask Integration: A simple and user-friendly interface built with Flask allows users to ask questions or provide comments and receive instant replies from the chatbot.

## How It Works
1. Preprocessing:
Input text is tokenized into smaller chunks called tokens.
Lemmatization is performed to standardize the tokens, reducing them to their base forms.
The resulting data is converted into a bag-of-words format, which represents the input text in a structured way for the RNN model.

2. Model Training:
An RNN model is trained on the processed data to learn from various text patterns.
The model is then fine-tuned to generate appropriate responses to user inputs.

3. Flask Integration:
The trained RNN model is integrated into a web interface using Flask.
The interface allows users to interact with the chatbot by typing questions or comments.
The chatbot processes the input, generates a response, and displays it to the user in real-time.

Installation and Setup
1. Clone the repository:
```git clone https://github.com/imaliabdullah/Portfolio-Project/tree/main/AI%20Chat-bot```

2. Navigate to the project directory:
```cd your-path```

3. Install the required dependencies:
```pip install -r requirements.txt```

4. Run the Flask app:
```python app.py```

5. Open your browser and go to http://localhost:5000 to interact with the chatbot.

## Dependencies
- Python 3.x
- Flask
- NLTK for tokenization and lemmatization
- Keras or PyTorch (for the RNN model)
- NumPy
- Other libraries mentioned in requirements.txt

## Future Improvements
- Expand the training data for more versatile responses.
- Improve the user interface for a more intuitive experience.
- Implement more advanced NLP techniques like transformers for enhanced understanding.

Here is the result:
https://github.com/user-attachments/assets/9739816a-4243-4f08-9c0f-bed182fc5abb

