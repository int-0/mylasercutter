
ORIGINAL_PAGES=$(sort $(wildcard *.svg))
CONVERTED_PAGES=$(ORIGINAL_PAGES:.svg=.pdf)

%.pdf: %.svg
	rsvg-convert -f pdf -o $@ $<

manual.pdf: $(CONVERTED_PAGES)
	pdftk $? cat output $@ 

all: CNC_mounting.pdf

clean:
	$(RM) CNC_mounting.pdf
	$(RM) *.pdf
	$(RM) *~
