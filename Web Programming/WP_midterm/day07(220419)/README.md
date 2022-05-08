# Responsive Web

## Viewport

```html
<meta
  name="“viewport”"
  content="“width"
  ="device-width,"
  user-scalable="yes”"
/>
<meta name="viewport" content="width=device-width, initial-scale=1.0" />
```

## Media Query

```html
<!DOCTYPE html>
<html>
  <head>
    <title>Responsive Web</title>
    <meta
      name="viewport"
      content="width=device-width, user-scalable=yes, initial-scale=1.0"
    />
    <style>
      body {
        background-color: lightgreen;
      }
      @media (max-width: 600px) {
        body {
          background-color: violet;
        }
      }
    </style>
  </head>
  <body>
    <h2>viewport</h2>
    <div>Imagination is more important than knowledge.</div>
  </body>
</html>
```

웹 페이지의 가로 크기가 600px이 되는 순간 violet 색상으로 변경된다.

## Pull-Down Menu with Input Tag

```html
<!DOCTYPE html>
<html>
  <head>
    <title>Pull-Down Menu</title>

    <style>
      input:checked + div {
        display: none;
      }
    </style>
  </head>

  <body>
    <input type="checkbox" />
    <div id="section">
      <h2>A Night for Counting Stars</h2>
      <br />
      <p>
        Autumn is full of the sky, as the season passes.<br />
        It seems that I can count all the stars in sky, <br />
        in autumn, without any worries.
      </p>
      <br />
      <p>
        Why I can't count all the faint stars in my heart,<br />
        Because morning comes easily,<br />
        Because tomorrow night is only left, <br />
        It is because my youth is not yet over, truly.
      </p>
    </div>
  </body>
</html>
```
