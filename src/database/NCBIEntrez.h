/*
 * Developed by Alexander Hart
 * Plant Computational Genomics Lab
 * University of Connecticut
 *
 * For information, contact Alexander Hart at:
 *     entap.dev@gmail.com
 *
 * Copyright 2017-2023, Alexander Hart, Dr. Jill Wegrzyn
 *
 * This file is part of EnTAP.
 *
 * EnTAP is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EnTAP is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EnTAP.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ENTAP_NCBIENTREZ_H
#define ENTAP_NCBIENTREZ_H

#include "../common.h"
#include "../FileSystem.h"

class NCBIEntrez {

public:

    // Required input for an Entrez Search
    struct EntrezInput {
        std::string database;
        std::string retmode;
        std::string rettype;
        std::string term;
        vect_str_t  uid_list;
    };

    struct EntrezResults {
        std::string count;
        vect_str_t uid_list;
    };

    // Entrez DATABASE types
    static const std::string NCBI_DATABASE_TAXONOMY;

    // Entrez RETTYPE types
    static const std::string NCBI_ENTREZ_RETTYPE_XML;

    // Entrez RETMODE types
    static const std::string NCBI_ENTREZ_RETMODE_TEXT;


    NCBIEntrez(FileSystem *fileSystem);
    ~NCBIEntrez();
    bool entrez_has_hits(EntrezInput &entrezInput);
    bool entrez_search(EntrezInput &entrezInput, EntrezResults &entrezResults);

#ifndef UNIT_TESTS
protected:
#endif

    typedef enum {
        ENTREZ_SEARCH,
        ENTREZ_SUMMARY,
        ENTREZ_FETCH
    } ENTREZ_TYPES;

    // Entrez Base URLs
    const std::string ESEARCH_BASE_URL = "https://eutils.ncbi.nlm.nih.gov/entrez/eutils/esearch.fcgi?";
    const std::string EPOST_BASE_URL   = "https://eutils.ncbi.nlm.nih.gov/entrez/eutils/epost.fcgi?";
    const std::string EFETCH_BASE_URL  = "https://eutils.ncbi.nlm.nih.gov/entrez/eutils/efetch.fcgi?";
    const std::string ESUMMARY_BASE_URL= "https://eutils.ncbi.nlm.nih.gov/entrez/eutils/esummary.fcgi?";

    // Entrez commands
    const std::string NCBI_ENTREZ_RETTYPE = "rettype=";
    const std::string NCBI_ENTREZ_RETMODE = "retmode=";
    const std::string NCBI_ENTREZ_DATABASE= "db=";
    const std::string NCBI_ENTREZ_UID     = "id=";
    const std::string NCBI_ENTREZ_TERM    = "term=";

    // Rettypes
    const std::string NCBI_ENTREZ_RETTYPE_COUNT = "count";

    // XML
    const std::string NCBI_ENTREZ_UID_XML_START = "<Id>";
    const std::string NCBI_ENTREZ_UID_XML_END   = "</Id>";
    const std::string NCBI_ENTREZ_COUNT_XML_START= "<Count>";
    const std::string NCBI_ENTREZ_COUNT_XML_END  = "</Count>";

    const std::string NCBI_ENTREZ_COUNT_ZERO     = "0";

    FileSystem *mpFileSystem;
    std::string generate_query(EntrezInput &entrezInput, ENTREZ_TYPES type);
    void process_term(std::string& term);
};

#endif //ENTAP_NCBIENTREZ_H
