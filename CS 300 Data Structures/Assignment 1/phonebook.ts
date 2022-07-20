// import './phonebook2.txt'
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



