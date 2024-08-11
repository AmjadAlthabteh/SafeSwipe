// Function to perform the Luhn algorithm
function luhnCheck(cardNumber) {
    let sum = 0;
    let alternate = false;

    for (let i = cardNumber.length - 1; i >= 0; i--) {
        let n = parseInt(cardNumber[i], 10);

        if (alternate) {
            n *= 2;
            if (n > 9) n -= 9;
        }

        sum += n;
        alternate = !alternate;
    }

    return (sum % 10 === 0);
}

// Function to detect card type based on prefix
function detectCardType(cardNumber) {
    const cardTypes = {
        Visa: /^4\d{12}(?:\d{3})?$/,
        MasterCard: /^5[1-5]\d{14}$/,
        Amex: /^3[47]\d{13}$/,
        Discover: /^6(?:011|5\d{2})\d{12}$/
    };

    for (const [type, pattern] of Object.entries(cardTypes)) {
        if (pattern.test(cardNumber)) {
            return type;
        }
    }

    return "Unknown";
}

document.getElementById("validateButton").addEventListener("click", function() {
    const cardNumber = document.getElementById("cardNumber").value.replace(/\s+/g, '');
    const resultDiv = document.getElementById("result");
    const cardTypeDiv = document.getElementById("cardType");

    if (luhnCheck(cardNumber)) {
        resultDiv.textContent = "The credit card number is valid.";
        resultDiv.style.color = "#4caf50";
    } else {
        resultDiv.textContent = "The credit card number is invalid.";
        resultDiv.style.color = "#f44336";
    }

    const cardType = detectCardType(cardNumber);
    cardTypeDiv.textContent = `Card Type: ${cardType}`;

    resultDiv.classList.add("show");
    cardTypeDiv.classList.add("show");
});
