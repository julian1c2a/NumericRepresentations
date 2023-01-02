DOXY_EXEC_PATH = C:/Users/julia/Dropbox/GitHub/NumericRepresentations/doxygen
DOXYFILE = C:/Users/julia/Dropbox/GitHub/NumericRepresentations/doxygen/-
DOXYDOCS_PM = C:/Users/julia/Dropbox/GitHub/NumericRepresentations/doxygen/perlmod/DoxyDocs.pm
DOXYSTRUCTURE_PM = C:/Users/julia/Dropbox/GitHub/NumericRepresentations/doxygen/perlmod/DoxyStructure.pm
DOXYRULES = C:/Users/julia/Dropbox/GitHub/NumericRepresentations/doxygen/perlmod/doxyrules.make

.PHONY: clean-perlmod
clean-perlmod::
	rm -f $(DOXYSTRUCTURE_PM) \
	$(DOXYDOCS_PM)

$(DOXYRULES) \
$(DOXYMAKEFILE) \
$(DOXYSTRUCTURE_PM) \
$(DOXYDOCS_PM): \
	$(DOXYFILE)
	cd $(DOXY_EXEC_PATH) ; doxygen "$<"
