# This is an implementation of an example from Programming Python

bob = %{:name => "Bob Smith", :age => 42, :pay => 30000, :job => "Developer"}
sue = %{:name => "Sue Jones", :age => 45, :pay => 40000, :job => "Designer"}
tom = %{:name => "Tom Little",:age => 50, :pay => 0, :job => nil}

# This is best with keyword list
db = []
db = db ++ [bob: bob]
db = db ++ [sue: sue]
db = db ++ [tom: tom]

for item <- db do
  {name,values} = item
  sValues = "{#{values |> Enum.map(&(Tuple.to_list(&1)) |> Enum.join(": ")) |> Enum.join(", ")}}"
  IO.puts("#{name} => \n #{sValues}")
end
