# Questions:

## Day 1
### Elixir:

> Strings in Elixir are represented internally by contiguous sequences of bytes known as binaries
- This should be answered tomorrow looking at the TOC.

> What is a technical grapheme?
- In linguistics, a grapheme is the smallest functional unit of a writing system.
- Tuple expressions will evaluate before the match:

```elixir
iex(37)> ^x = 2
** (MatchError) no match of right hand side value: 2
    (stdlib 5.2) erl_eval.erl:498: :erl_eval.expr/6
    iex:37: (file)
iex(37)> {:ok, result} = {:ok, ^x = 2}
** (MatchError) no match of right hand side value: 2
    (stdlib 5.2) erl_eval.erl:498: :erl_eval.expr/6
    iex:37: (file)
iex(37)> {:ok, result} = {:ok, ^x = 1}
{:ok, 1}
iex(38)> result
1 
```

### Game Programming
- `auto` is a really cool new feature in C++; still be careful since C++
- Using this keyword means it will copy the value so **avoid with objects**.


## Day 2
### Elixir:
- The capture operator is not quite intuitive even if it's just an anonymous function. There must be a reason for this which I don't understand yet.
> Unicode organizes all of the characters in its repertoire into code charts, and each character is given a unique numerical index. This numerical index is known as a Code Point.

- > A **binary** is a bitstring where the number of bits is divisible by 8.
- > A **charlist** is a list of integers where all the integers are valid code points.


## Day 3
### Elixir
- > Elixir does not provide loop constructs. Instead we leverage recursion and high-level functions for working with collections.
- > The process of taking a list and reducing it down to one value is known as a reduce algorithm and is central to functional programming.
- > While Elixir allows us to write recursive code, most operations we perform on collections is done with the help of the Enum and Stream modules. Let's learn how.
- > As an alternative to Enum, Elixir provides the Stream module which supports lazy operations.
- > Instead of generating intermediate lists, streams build a series of computations that are invoked only when we pass the underlying stream to the Enum module. Streams are useful when working with large, possibly infinite, collections.
- > In Elixir, all code runs inside processes. Processes are isolated from each other, run concurrent to one another and communicate via message passing.

## Day 4
### Elixir
- > By default, files are opened in binary mode, which requires developers to use the specific IO.binread/2 and IO.binwrite/2 functions from the IO module
- > A file can also be opened with :utf8 encoding, which tells the File module to interpret the bytes read from the file as UTF-8-encoded bytes.
- > Notice that the version with ! returns the contents of the file instead of a tuple, and if anything goes wrong the function raises an error.
- If you open a file, write to it and then accidentily throw an error then everything is lost.
- Just like other languages, we should avoid making copies since they're slow.
- So, use `Enum.intersperse()` instead of `Enum.join()` when dealing with either large data or merging string data to print.
> The difference between "iodata" and "chardata" is precisely what said integer represents. For iodata, the integers represent bytes. For chardata, the integers represent Unicode codepoints.

## Day 5
### Elixir
- > An alias in Elixir is a capitalized identifier (like String, Keyword, etc) which is converted to an atom during compilation. 
- > Elixir treats documentation as first-class and provides many functions to access documentation.

## Day 6
### Elixir
- Learned about another data structure called structs which are sort of like the same thing in C.
- Learned about how to use Elixir's version of Comprehensions; familiar with these thanks to Python.
- 




# Notable Stuff + Ideas
= Distributed Mean via Elixir Processes
= Caching via Elixir + State
== LRU in Elixir
= Social Media Feed?

https://github.com/elixir-lang/ex_doc