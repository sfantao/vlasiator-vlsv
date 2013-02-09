/** This file is part of VLSV file format.
 * 
 *  Copyright 2011-2013 Finnish Meteorological Institute
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MESH_METADATA_VISIT_QUAD_MULTI_H
#define MESH_METADATA_VISIT_QUAD_MULTI_H

#include <stdint.h>

#include <mesh_metadata_visit.h>

namespace vlsvplugin {
   
   class VisitQuadMultiMeshMetadata: public VisitMeshMetadata {
    public:
      VisitQuadMultiMeshMetadata();
      ~VisitQuadMultiMeshMetadata();
      
      bool getDomainInfo(VLSVReader* vlsv,int domain,const uint64_t*& domainOffsets,
			 const uint64_t*& ghostOffsets,const uint64_t*& variableOffsets);
      const uint64_t* getDomainOffsets();
      const uint64_t* getGhostOffsets();
      const float* getMeshBoundingBox();
      uint64_t getNumberOfGhostCells(int domain) const;
      uint64_t getNumberOfRealCells(int domain) const;
      uint64_t getNumberOfTotalCells(int domain) const;
      const uint64_t* getVariableOffsets();
      
      bool read(VLSVReader* vlsv,const std::map<std::string,std::string>& attribs);
      
    protected:
      bool domainMetadataRead;        /**< If true, domain metadata has been read.*/
      bool meshMetadataRead;          /**< If true, mesh metadata has been read.*/
      uint64_t* domainOffsets;
      uint64_t* ghostOffsets;
      uint64_t* variableOffsets;
      float* meshCoordinates;
      
      bool readDomains(VLSVReader* vlsv);
   };
   
} // namespace vlsvplugin

#endif
