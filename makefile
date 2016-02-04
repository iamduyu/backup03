
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

# stream
stream_bin = stream
stream_src = stream.cpp
$(stream_bin) : $(stream_src)
	g++ -std=c++14 $(stream_src) -o $(stream_bin)


# assign
assign_bin = assign
assign_src = assign.cpp
$(assign_bin) : $(assign_src)
	g++ -std=c++14 $(assign_src) -g -o $(assign_bin)

# ibm
ibm_bin = ibm
ibm_src = ibm.cpp
$(ibm_bin) : $(ibm_src)
	g++ -std=c++14 $(ibm_src) -g -o $(ibm_bin)

# excep
excep_bin = excep
excep_src = excep.cpp
$(excep_bin) : $(excep_src)
	g++ -std=c++14 $(excep_src) -g -o $(excep_bin)

.DEFAULT_GOAL = excep
