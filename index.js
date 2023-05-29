document.addEventListener('DOMContentLoaded', function() {
    var userInput = document.getElementById('user-input');
    var sendBtn = document.getElementById('send-btn');
    var chatLog = document.getElementById('chat-log');

    sendBtn.addEventListener('click', function() {
        var userMessage = userInput.value;
        appendMessage('user', userMessage);

        // Обработка на съобщението от потребителя
        var botResponse = getBotResponse(userMessage);
        appendMessage('bot', botResponse);

        userInput.value = '';
    });

    function appendMessage(sender, message) {
        var messageElement = document.createElement('div');
        messageElement.classList.add(sender + '-message');
        messageElement.textContent = message;
        chatLog.appendChild(messageElement);
    }

    function getBotResponse(userMessage) {
        // Тук можете да добавите логика за отговорите на бота според входящото съобщение
        // Пример:
        let m=userMessage.toLowerCase();
        if (m=='здравей') return 'Здравейте! Как мога да ви помогна?';
        if (m=='как си') return 'Аз съм добре. Ти как си?';
        if (m=='създател') return 'Никола Манолов';
        if (m=='никола манолов') return 'Велик човек. Най-добрия програмист в България. Може да се похвали със своите медали. Много е красив и готин.';
        if (m=='ивайла бозова') return 'Това е болно дете от Хасково което е много тъпо. Гадже е с целия град.';
        if (m=='тони недялкова') return 'Ще го запомня. Бате пас е.';
        return 'Извинете, не разбирам въпроса ви.';
        
    }
});
