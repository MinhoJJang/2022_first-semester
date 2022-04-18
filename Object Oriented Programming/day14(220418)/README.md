# 0415 class

## equals

```java
String s1 = new String(“Hello”);
String s2 = new String(“Hello”);
boolean strEqual = (s1 == s2)

strEqual == False
주소값 다름
```

```java
String s1 = new String(“Hello”);
String s2 = s1
boolean strEqual = (s1 == s2)

True
같은 주소값 복사
```

```java
String s1 = new String(“Hello”);
String s2 = new String(“Hello”);
boolean strEqual = (s1.equals(s2));

True
주소내부 데이터값 같음
```

```java
public Book(String name) { this.name = name; }
public void changeBook(Book book){
    book = new Book(“Biology”); // book is changed
    /*
     book = new Book();
     book.setName("Biology");
    */
}
public void doStuff() {
    Book jacksBook = new Book(“Java”);
    changeBook(jacksBook);
    System.out.println(jacksBook.getName());
}

Java 출력
```

```java
public void changeBook(Book book)
{
   book.setName(“Biology”);
}
public void doStuff()
{
    Book jacksBook = new Book(“Java”);
    changeBook(jacksBook);
    System.out.println(jacksBook.getName());
}

setter로 객체의 내부 데이터값을 바꿔주었으므로 Biology 출력
```
