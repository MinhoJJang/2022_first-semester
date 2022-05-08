# Web Programming - CSS3 Layout, Combinators

## List

리스트를 꾸미는 CSS 파트이다. 1, 2 같은 숫자 대신 이미지를 넣을 수도 있고, 이미지의 위치를 바꿀수도 있다.

- HTML5 List

```
<ul> = unordered list
<ol> = ordered list
```

- CSS3 List Property

```
list style type
list style image
list style position
```

## Overflow

정해진 틀보다 글자수가 넘어갔을 때, 어떻게 표시할 것인지 정한다.

## Combinators

//TODO

### CSS3 Pseudo classes

내가 한번 들어갔던 사이트는 보라색으로 링크색이 바뀐다던지, 검색창에 onclick을 하면 색깔이 바뀐다던지.. 이런것을 하는 css이다.

```html
<style>
  /* unvisited link */
  a:link {
    color: blue;
  }
  /* visited link */
  a:visited {
    color: purple;
  }
  /* mouse over link */
  a:hover {
    color: red;
  }
  /* selected link */
  a:active {
    color: green;
  }
</style>
```

이외에도 checked, disabled, empty, enabled, focus, required 등등과 같은 속성들이 있다. 외울 필요는 없고, 다만 어떻게, 언제 사용하는지 알아야 할 것이다.

### CSS3 Pseudo elements

태그 전체가 아닌, 태그 내부 element 중에서 일부를 style해주기 위해 필요하다.

```css
selector::pseudo element {
  property: value;
}
```

```html
<style>
  p::first-line {
    color: #ff0000;
    font-variant: small-caps;
  }
  p::first-letter {
    color: #800000;
    font: bold xx-large times;
  }
</style>
```

이외의 부가적인 것들 중에서, selection의 경우 사용자가 드래그한 부분의 색깔을 바꿔주는 역할을 한다.

## Miscellaneous

### CSS3 Media Query

```html
<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8" />
    <title>CSS3 Media Query</title>
    <style>
      @media (min-width: 600px) {
        body {
          background-color: green;
        }
      }
      @media (min-width: 768px) {
        body {
          background-color: blue;
        }
      }
    </style>
  </head>
  <body>
    With Media query, the page is shown differently depending on the resolution
    of the screen.
  </body>
</html>
```

## Which Styles to Apply?

### !important Rule

```html
<!DOCTYPE html>
<html>
  <head>
    <title>Which Styles to Apply?</title>
    <style>
      p {
        color: purple !important;
      }
      p {
        color: blue;
      }
    </style>
  </head>
  <body>
    <p>Which Styles to Apply?</p>
  </body>
</html>
```

위와 같은 코드에서, css는 Cascading, 즉 폭포처럼 맨 아래에 적용된, 즉 맨 마지막에 적용된 css를 실제로 적용한다. 이때 important는 그 css 속성을 우선시하게 만들어주는 역할을 한다.

### ID and Class Selector

```html
<!DOCTYPE html>
<html>
  <head>
    <title>Which Styles to Apply?</title>
    <style>
      h1#top {
        color: blue;
      }
      h1.top {
        color: red;
      }
      h1 {
        color: green;
      }
    </style>
  </head>
  <body>
    <h1 id="top">Which Styles to Apply?</h1>
    <h1 class="top">Which Styles to Apply?</h1>
    <h1>Which Styles to Apply?</h1>
  </body>
</html>
```

id 는 class보다 더 specific하고, class는 element보다 specific하다.

### Declaration Order

```html
<!DOCTYPE html>
<html>
  <head>
    <title>Which Styles to Apply?</title>
    <style>
      h1 {
        color: red;
      }
      h1 {
        color: blue;
      }
    </style>
  </head>
  <body>
    <h1>Which Styles to Apply?</h1>
  </body>
</html>
```

맨 마지막에 적용된 h1 css 속성의 color가 blue 이므로 blue 색상이 나오게 된다.

## CSS Validation

Css 파일이 정상적인지 확인하기 위해 아래 사이트에서 확인할 수 있다.

[http://jigsaw.w3.org/css-validator/](http://jigsaw.w3.org/css-validator/)
[http://www.cssportal.com/css-validator/](http://www.cssportal.com/css-validator/)
