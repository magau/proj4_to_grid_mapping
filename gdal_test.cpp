#include "gdal_priv.h"
#include "cpl_conv.h" // for CPLMalloc()

int main()
{
    GDALDataset  *poDataset;
    GDALAllRegister();
    double adfGeoTransform[6];

    poDataset = (GDALDataset *) GDALOpen( "/home/jmacedo/data/MTG_Chain/Inputs/NWP/2013/08/04/LSASAF_ECMWF_SKT_MTG-Disk_20130804120000.nc", GA_ReadOnly );
    if( poDataset != NULL ) {
        printf( "Driver: %s/%s\n",
        poDataset->GetDriver()->GetDescription(),
        poDataset->GetDriver()->GetMetadataItem( GDAL_DMD_LONGNAME ) );
        printf( "Size is %dx%dx%d\n",
                poDataset->GetRasterXSize(), poDataset->GetRasterYSize(),
                poDataset->GetRasterCount() );
        if( poDataset->GetProjectionRef()  != NULL )
            printf( "Projection is `%s'\n", poDataset->GetProjectionRef() );
        if( poDataset->GetGeoTransform( adfGeoTransform ) == CE_None ) {
            printf( "Origin = (%.6f,%.6f)\n",
                    adfGeoTransform[0], adfGeoTransform[3] );
            printf( "Pixel Size = (%.6f,%.6f)\n",
                    adfGeoTransform[1], adfGeoTransform[5] );
        }
    }
}
