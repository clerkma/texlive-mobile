noinst_LIBRARIES = liboptimizer.a

liboptimizer_a_SOURCES = \
	AttributeExtractor.hpp      AttributeExtractor.cpp \
	DependencyGraph.hpp \
	GroupCollapser.hpp          GroupCollapser.cpp  \
	OptimizerModule.hpp \
	RedundantElementRemover.hpp RedundantElementRemover.cpp \
	SVGOptimizer.hpp            SVGOptimizer.cpp \
	TextSimplifier.hpp          TextSimplifier.cpp \
	TransformSimplifier.hpp     TransformSimplifier.cpp \
  	WSNodeRemover.hpp           WSNodeRemover.cpp

AM_CXXFLAGS = -I$(dvisvgm_srcdir)/libs/variant/include
