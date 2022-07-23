class Book {
  private title: string
  private isbn: number
  private authors: string
  private publisher: string

  constructor(bookTitle: string, isbnNum: number, bookAuthor: string, bookPublish: string) {
    this.title = bookTitle
    this.isbn = isbnNum
    this.authors = bookAuthor
    this.publisher = bookPublish
  }

  setTitle(title: string) {
    this.title = title
  }

  getTitle(): string {
    return this.title
  }
}

