
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

# template
template_bin = template
template_src = template.cpp
$(template_bin) : $(template_src)
	g++ -std=c++14 $(template_src) -g -o $(template_bin)

# stl
stl_bin = stl
stl_src = stl.cpp
$(stl_bin) : $(stl_src)
	g++ -std=c++14 $(stl_src) -g -o $(stl_bin)

# ctor2
ctor2_bin = ctor2
ctor2_src = ctor2.cpp
$(ctor2_bin) : $(ctor2_src)
	g++ -std=c++14 $(ctor2_src) -g -o $(ctor2_bin)

# ctor4
ctor4_bin = ctor4
ctor4_src = ctor4.cpp
$(ctor4_bin) : $(ctor4_src)
	g++ -std=c++14 $(ctor4_src) -g -o $(ctor4_bin)


# ni
ni_bin = ni
ni_src = ni.cpp
$(ni_bin) : $(ni_src)
	g++ -std=c++14 $(ni_src) -g -o $(ni_bin)


# ni2
ni2_bin = ni2
ni2_src = ni2.cpp
$(ni2_bin) : $(ni2_src)
	g++ -std=c++14 -pedantic $(ni2_src) -g -o $(ni2_bin)


.DEFAULT_GOAL = ni2
