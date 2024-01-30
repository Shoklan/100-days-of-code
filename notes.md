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

### Game Progamming
- `auto` is a really cool new feature in C++; still be careful since C++
- Using this keyword means it will copy the value so **avoid with objects**.
- 
