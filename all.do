export HERE=`pwd`
export LIBOBJ=`find $HERE/src -name "*.c" | sed 's/\.c/\.o/g'`
redo-ifchange libnitro.a
redo-ifchange test/basic
