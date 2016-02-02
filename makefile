# example
example: main.cpp
	g++ -std=c++14 main.cpp -o example

# copy
copy_bin = copy
copy_src = copy.cpp
$(copy_bin): $(copy_src)
	g++ -std=c++14 $(copy_src) -o $(copy_bin)

# ref
ref_bin = ref
ref_src = ref.cpp
$(ref_bin) : $(ref_src)
	g++ -std=c++14 $(ref_src) -o $(ref_bin)

# ctor
ctor_bin = ctor 
ctor_src = ctor.cpp
$(ctor_bin) : $(ctor_src)
	g++ -std=c++14 $(ctor_src) -o $(ctor_bin)

# functor
functor_bin = functor
functor_src = functor.cpp
$(functor_bin) : $(functor_src)
	g++ -std=c++14 $(functor_src) -o $(functor_bin)
