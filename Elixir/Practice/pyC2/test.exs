# Test script for misc

keyValueSplit = fn s ->
  [keyword, value] = String.split(s, ":")
  |> Enum.map( &(String.trim_leading(&1)))
  [keyword, value]
end

lines = File.read!("people-data") |> String.split("\n")

    # for line in file
    db = for line <- lines,
      into: [] do
      # process the line to break apart key, values
      [key, values] = line
        |> String.trim
        |> String.split(":", parts: 2)
        |> Enum.map(&(String.trim(&1)))

      # clean up the values for processing
      cValues = values
        |> String.replace(~r"[{}]", "")
        |> String.split(",")
        |> Enum.map( &(keyValueSplit.( &1 )))

      # insert them into the map
      mp = for item <- cValues,
        into: %{} do
        [key, value] = item
        {key, value}
      end

      # mp = %{}
      [key, mp]
    end

IO.inspect(db)
