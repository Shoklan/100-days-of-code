# This is an implementation of an example from Programming Python
# This writes and reads from a "DB" from a file:

defmodule ExampleDB do
  @moduledoc """
  Module to pretend to be a simple database.
  """
  @moduledoc since: "1.0.0"

  @doc since: "1.0.0"
  @doc """
  Function to read the 'db' from a file.
  """
  def loadFromFile(path \\ "people-data") do
    lines = File.read!(path)
      |> String.split("\n")
      |> Enum.filter(&(&1 != ""))

    # for line in file
    db = for line <- lines,
      into: [] do
      # process the line to break apart key, values
      # and remove any extra blanks
      [key, values] = line
        |> String.trim
        |> String.split(":", parts: 2)
        |> Enum.map(&(String.trim(&1)))

      # clean up the values for processing
      cValues = values
        |> String.replace(~r"[{}]", "")
        |> String.split(",")
        |> Enum.map( &(keyValueSplit( &1 )))

      # insert them into the map
      mp = for item <- cValues,
        into: %{} do
        [key, value] = item
        {key, value}
      end

      # mp = %{}
      [key, mp]
    end
    # return it
    db
  end

  @doc since: "1.0.0"
  @doc """
  Function to write the Keyword-List of Maps to disk.
  """
  def saveToFile(path, db) do
    # Save the "DB" to a file
    file = File.open(path, [:write])
    for item <- db do
      [name, values] = item
      # convert to string representation for disk
      sValues = "#{
        values
        |> Enum.map(&(Tuple.to_list(&1))
        |> Enum.join(": "))
        |> Enum.join(", ")}"
      IO.puts(sValues)
      content = "#{name} : #{sValues}\n"
      IO.puts(content)
      IO.binwrite(file, content)
    end

    File.close(file)
  end

  @doc false
  defp keyValueSplit(s) do
    # Helper to split and clean entries
    [keyword, value] = String.split(s, ":")
      |> Enum.map( &(String.trim_leading(&1)))
    [keyword, value]
  end
end
