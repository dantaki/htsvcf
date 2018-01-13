#include <stdio.h>
#include <stdlib.h>
#include <htslib/vcf.h>

int main(int argc, char **argv)
{
	if (argc != 2){ return EXIT_FAILURE; }
	htsFile * inf = bcf_open(argv[1], "r");
	if (inf == NULL){ return EXIT_FAILURE; }
	bcf_hdr_t *hdr = bcf_hdr_read(inf);
	fprintf(stderr, "File %s contains %i samples\n", argv[1], bcf_hdr_nsamples(hdr));

	bcf_hdr_destroy(hdr);
	bcf_close(inf);
	return 0;
}
