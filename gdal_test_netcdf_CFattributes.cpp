
#include <cfloat>
#include <map>
#include <vector>

#include "cpl_string.h"
#include "cpl_conv.h" // for CPLMalloc()

#include "gdal_frmts.h"
#include "gdal_pam.h"
#include "gdal_priv.h"

#include "netcdf.h"
#include "ogr_spatialref.h"
#include "ogrsf_frmts.h"

#include "netcdfdataset.h"

int main() {

    const char* proj4_str = "\
+proj=geos \
+lon_0=0 \
+h=35785831 \
+x_0=0 \
+y_0=0 \
+a=6378169.0 \
+b=6356583.8 \
+units=m \
+sweep=y \
+no_defs";

    char* wkt_proj_2;
    const char* wkt_proj = "\
PROJCS[\"unnamed\",\
GEOGCS[\"unknown\",\
DATUM[\"unknown\",\
SPHEROID[\"Spheroid\",638169.0,295.488065897]],\
PRIMEM[\"Greenwich\",0],\
UNIT[\"degree\",0.0174532925199433]],\
PROJECTION[\"Geostationary_Satellite\"],\
PARAMETER[\"central_meridian\",0],\
PARAMETER[\"satellite_height\",35785831],\
PARAMETER[\"false_easting\",0],\
PARAMETER[\"false_northing\",0]]";

    //OGRSpatialReference poSRS(wkt_proj);
    OGRSpatialReference poSRS;
    //poSRS.SetProjection(wkt_proj);
    poSRS.importFromProj4(proj4_str);
    poSRS.exportToWkt(&wkt_proj_2); 
    printf( "Projection is `%s'\n", wkt_proj_2);


     for( int iMap = 0; poNetcdfSRS_PT[iMap].WKT_SRS != nullptr; iMap++ )
    {
        printf("%s\n", poNetcdfSRS_PT[iMap].WKT_SRS);
        //if( EQUAL(pszProjection, poNetcdfSRS_PT[iMap].WKT_SRS) )
        //{
        //    nMapIndex = iMap;
        //    poMap = poNetcdfSRS_PT[iMap].mappings;
        //    break;
        //}
    }

}
