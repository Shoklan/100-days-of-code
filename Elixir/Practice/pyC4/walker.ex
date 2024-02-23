# This is an implementation of an example from Programming Python
# This walks down a path naming all the files in every directory

defmodule Walker do
  @moduledoc """
  Module to recurse through a directory and run a function.
  """

  @moduledoc since: "1.0.0"
  def walk(path, f) do
    for target <- File.ls!(path) do
      cond do
        File.dir?(target) -> walk(target, f)
        true -> f.(target)
      end
    end
  end
end
