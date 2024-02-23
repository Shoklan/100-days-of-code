defmodule LootTable do
  @moduledoc """
  Acts as a lookup table for loot.
  """
  @table [
    {:common, ["0": "Cucumber", "33": "Lemon", "66": "Lime"]},
    {:uncommon, ["0": "Banana", "50": "Apple", "66": "Cherry"]},
    {:rare, ["0": "Mango", "50": "Honeydew Melon"]},
    {:legendary, ["0": "Pineapple", "90": "Dragonfruit"]}
  ]

  def start_link do
    Task.start_link(fn -> loop() end)
  end

  defp lookup(rarity) do
    roll = Enum.random(1..100)

    # select the values based on rarity
    possible = @table[rarity]


    levels = possible
    |> Keyword.keys()
    # convert keys to strings so filter them by roll value
    |> Enum.map( &(to_string(&1)) )
    |> Enum.filter( &(&1 < to_string(roll)) )
    # return the filtered values to existing atoms
    |> Enum.map(&( String.to_existing_atom(&1)))

    # I hated retyping this
    subset = Keyword.take(possible, levels)

    # # collect the item
    item = cond do
      # If length is 1, return head so not empty
      length(subset) == 1 -> subset |> hd |> Tuple.to_list |> tl
      # If longer, pull the last elem and extract
      true -> subset |> List.last() |> Tuple.to_list |> tl
    end

    # return the item
    item
  end

  defp loop() do
    receive do
      {:get, key, caller} ->
        send(caller, lookup(key))
        loop()
    end
  end
end
