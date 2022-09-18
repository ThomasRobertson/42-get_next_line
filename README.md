
<h1 align="center">
  get_next_line
  <br>
</h1>

<h4 align="center">Reading a line from a fd is way too tedious.
<br>
<br>
</h4>

<p align="center">
  <a href="https://github.com/ThomasRobertson/42-get_next_line">
    <img src="https://tokei.rs/b1/github/ThomasRobertson/42-get_next_line"
         alt="Line of Code">
  </a>
  <a href="https://github.com/ThomasRobertson/42-get_next_line">
    <img src="https://img.shields.io/github/languages/code-size/ThomasRobertson/42-get_next_line"
         alt="Size">
  </a>
  <a href="https://github.com/ThomasRobertson/42-get_next_line">
    <img src="https://img.shields.io/github/languages/top/ThomasRobertson/42-get_next_line"
         alt="License">
  </a>
  <a href="https://github.com/ThomasRobertson/42-get_next_line">
    <img src="https://img.shields.io/github/license/ThomasRobertson/42-get_next_line"
         alt="License">
  </a>
  <a href="https://github.com/ThomasRobertson/42-get_next_line/actions/workflows/norminette-action.yml">
    <img src="https://github.com/ThomasRobertson/42-get_next_line/workflows/Build/badge.svg"
         alt="Norminette Action">
  </a> 
  <a href="https://github.com/ThomasRobertson/42-get_next_line/actions/workflows/norminette-action.yml">
    <img src="https://github.com/ThomasRobertson/42-get_next_line/workflows/Norm Check/badge.svg"
         alt="Norminette Action">
  </a>
  <a href="https://github.com/ThomasRobertson/42-get_next_line/actions/workflows/norminette-action.yml">
    <img src="https://github.com/ThomasRobertson/42-get_next_line/workflows/Tripouille Tester/badge.svg"
         alt="Norminette Action">
  </a>
</p>

<p align="center">
  <a href="#summary">Summary</a> •
  <a href="#how-it-work">How It Work</a> •
  <a href="#how-to-use">How To Use</a> •
  <a href="#license">License</a>
</p>

## Summary

This function read from a file descriptor and return a line when reaching an EOF or '\n'.

> This project is part of 42 Paris' curriculum. You can check the full subject in the subject pdf included in this repo.

## How It Work

The function read a specified number of bytes from the file descriptor, using the GNL_BUFFER variable. If a EOF or a '\n' (new line) has been found, the function store the rest of the buffer and return a line.

The bonus can manage multiple file descriptor open at the same time, but if the function is stopped while the end has not been reached, leaks can occur. This is why the mandatory version is instead use in my Libft.

## How To Use

Clone this GitHub repos

```bash
git clone https://github.com/ThomasRobertson/42-get_next_line
```
The function does not include any main function, and need to be either compile with a file containing the main function, or use within a library.

## License

MIT
