import readline = require('readline')

class Contact {
  private firstName: string | undefined
  private lastName: string | undefined
  private phoneNum: number | undefined

  constructor(fName?: string, lName?: string, num?: number) {
    this.firstName = fName
    this.lastName = lName
    this.phoneNum = num
  }

  getFirstName(): string | undefined {  
    if (this.firstName) {
      return this.firstName
    }

    return undefined
  }

  getLastName(): string | undefined {
    if (this.lastName) {
      return this.lastName
    }

    return undefined
  }

  getPhoneNum(): number | undefined {
    if (this.phoneNum) {
      return this.phoneNum
    }

    return undefined
  }
}

const input = document.getElementsByTagName('input')[0]
console.log(input)

function readFile(input: HTMLInputElement) {
  let phoneBook = [] as Contact[]
  if (input !== null) {
    let file = input.files![0]
    let fileReader = new FileReader()
    fileReader.readAsText(file)

    fileReader.addEventListener('load', () => {
      let resultString = fileReader.result as string
      let stripped = resultString.split(/\r\n|\n/);

      for (let i = 0; i < stripped.length; i++) {
        let temp = stripped[i].split(" ")
        var contact = new Contact(temp[0], temp[1], parseInt(temp[2]))
        phoneBook.push(contact)
      }
    })
    fileReader.onerror = function () {
      alert(fileReader.error)
    }
  }
}

input.addEventListener('change', (e) => {
  readFile(input)
})

function readUserInput() {
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
  })

  rl.question("Phonebook application, choose operation (A(Add) | S(Search) | D(Delete) | L(List) | Q(Quit)", function (answer) {
    if (answer === 'A') {
      console.log('asdkasj;dsad')

    } else if (answer === 'S') {

    }
  })
}

readUserInput()

function search(contactBook: Contact[], contact: Contact, totalLineFiles: number): void {
  for (let i = 0; i < totalLineFiles; i++) {
    if (contact.getFirstName() === contactBook[i].getFirstName() && contact.getLastName() === contactBook[i].getLastName()) {
      console.log('First Name: %s, Last Name: %s', contact.getFirstName(), contact.getLastName())
    }
  }
}

function list(contactBook: Contact[], totalLineFiles: number): void {
  for (let i = 0; i < totalLineFiles; i++) {
    if (contactBook[i].getFirstName() !== "") {
      console.log('First Name: %s, Last Name: %s， Phone Number: %d', contactBook[i].getFirstName(), contactBook[i].getLastName(), contactBook[i].getPhoneNum())
    } else {
      return
    }
  }
}

function addContact(contactBook: Contact[], contact: Contact, totalLineFiles: number): Contact {
  totalLineFiles++
  contactBook.push(contact)
  return contactBook[totalLineFiles - 1]
}

function deleteContact(contactBook: Contact[], firstName: string, lastName: string, totalLineFiles: number): Contact {
  totalLineFiles--
  for (let i = 0; i < totalLineFiles; i++) {
    if (contactBook[i].getFirstName() === firstName && contactBook[i].getLastName() === lastName) {
      contactBook.splice(i, 1)
    }
  }

  return contactBook[totalLineFiles - 1]
}



