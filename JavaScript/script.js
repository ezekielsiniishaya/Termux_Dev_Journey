const questions = [
    {
        question: "What is the capital of France?",
        options: ["Paris", "London", "Rome"],
        correctOption: "Paris"
    },
    {
        question: "Which planet is known as the Red Planet?",
        options: ["Earth", "Mars", "Jupiter"],
        correctOption: "Mars"
    },
    {
        question: "What is the largest mammal?",
        options: ["Elephant", "Blue Whale", "Giraffe"],
        correctOption: "Blue Whale"
    }
];

let currentQuestionIndex = 0;
let score = 0;
let selectedOption = null;

function showQuestion() {
    const questionElement = document.getElementById("question");
    const optionsElement = document.getElementById("options");

    const currentQuestion = questions[currentQuestionIndex];
    questionElement.textContent = currentQuestion.question;

    optionsElement.innerHTML = '';
    currentQuestion.options.forEach(option => {
        const button = document.createElement("button");
        button.textContent = option;
        button.onclick = () => selectOption(button, option);
        optionsElement.appendChild(button);
    });

    selectedOption = null;
    document.getElementById("next-btn").disabled = true;
}

function selectOption(button, option) {
    const optionsElement = document.getElementById("options");
    Array.from(optionsElement.children).forEach(btn => btn.classList.remove("selected"));
    button.classList.add("selected");
    selectedOption = option;
    document.getElementById("next-btn").disabled = false;
}

function nextQuestion() {
    const currentQuestion = questions[currentQuestionIndex];
    if (selectedOption === currentQuestion.correctOption) {
        score++;
    }
    currentQuestionIndex++;
    if (currentQuestionIndex < questions.length) {
        showQuestion();
    } else {
        showScore();
    }
    document.getElementById("next-btn").disabled = true;
}

function showScore() {
    const quizContainer = document.getElementById("quiz-container");
    quizContainer.innerHTML = `<h1>Quiz Completed</h1><p>Your score: ${score} / ${questions.length}</p>`;
}

document.addEventListener("DOMContentLoaded", showQuestion);
