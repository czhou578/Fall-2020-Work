"use strict";
exports.__esModule = true;
var readline = require("readline");
var Contact = /** @class */ (function () {
    function Contact(fName, lName, num) {
        this.firstName = fName;
        this.lastName = lName;
        this.phoneNum = num;
    }
    Contact.prototype.getFirstName = function () {
        if (this.firstName) {
            return this.firstName;
        }
        return undefined;
    };
    Contact.prototype.getLastName = function () {
        if (this.lastName) {
            return this.lastName;
        }
        return undefined;
    };
    Contact.prototype.getPhoneNum = function () {
        if (this.phoneNum) {
            return this.phoneNum;
        }
        return undefined;
    };
    return Contact;
}());
var input = document.getElementsByTagName('input')[0];
console.log(input);
function readFile(input) {
    var phoneBook = [];
    if (input !== null) {
        var file = input.files[0];
        var fileReader_1 = new FileReader();
        fileReader_1.readAsText(file);
        fileReader_1.addEventListener('load', function () {
            var resultString = fileReader_1.result;
            var stripped = resultString.split(/\r\n|\n/);
            for (var i = 0; i < stripped.length; i++) {
                var temp = stripped[i].split(" ");
                var contact = new Contact(temp[0], temp[1], parseInt(temp[2]));
                phoneBook.push(contact);
            }
        });
        fileReader_1.onerror = function () {
            alert(fileReader_1.error);
        };
    }
}
input.addEventListener('change', function (e) {
    readFile(input);
});
function readUserInput() {
    var rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });
    rl.question("Phonebook application, choose operation (A(Add) | S(Search) | D(Delete) | L(List) | Q(Quit)", function (answer) {
        if (answer === 'A') {
            console.log('asdkasj;dsad');
        }
        else if (answer === 'S') {
        }
    });
}
readUserInput();
