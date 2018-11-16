
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

int main() {

    char* wkt_proj_2;
    const char* wkt_proj = "\
PROJCS[\"unnamed\",\
GEOGCS[\"unknown\",\
DATUM[\"unknown\",\
SPHEROID[\"Spheroid\",6371229,298.257223563]],\
PRIMEM[\"Greenwich\",0],\
UNIT[\"degree\",0.0174532925199433]],\
PROJECTION[\"Geostationary_Satellite\"],\
PARAMETER[\"central_meridian\",0],\
PARAMETER[\"satellite_height\",35785831],\
PARAMETER[\"false_easting\",0],\
PARAMETER[\"false_northing\",0]]";

    OGRSpatialReference poSRS(wkt_proj);
    //poSRS.SetProjection(wkt_proj);
    poSRS.exportToWkt(&wkt_proj_2); 
    printf( "Projection is `%s'\n", wkt_proj_2);
}
