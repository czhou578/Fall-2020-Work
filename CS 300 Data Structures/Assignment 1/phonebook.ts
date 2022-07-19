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

const input = document.getElementsByTagName('input')

async function main() {
  let phoneBook = [] as Contact[]

  console.log(text)
}

main()
 


