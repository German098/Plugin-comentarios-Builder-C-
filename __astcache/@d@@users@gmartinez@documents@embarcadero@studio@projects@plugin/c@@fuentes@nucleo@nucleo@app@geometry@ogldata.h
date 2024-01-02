#ifndef OGLDATAH
#define OGLDATAH
//------------------------------------------------------------------------------
#include <glut.h>
#include <vector>
#include <System.IniFiles.hpp>
#include <cxGraphics.hpp>
#include <XMLIntf.hpp>
#include "_defines.h"
#include "_gpoint3d.h"
#include "functions.h"
#include <map>

#define INES_GLU_MAXORDER	   7 // vuelto a cambiar 20/10/2014
#define INES_GLU_TOLERANCE	   1e-5

#define DEFAULT_DITEMS_POL	   100
#define DEFAULT_DITEMS_LIST	   1000

#define BITMAP_MAT_WIDTH_SMALL 30
#define BITMAP_MAT_WIDTH_HALF  50
#define BITMAP_MAT_WIDTH_LARGE 70

#define MAT_PREVIEW_VIRTUAL	   0
#define MAT_PREVIEW_PBR		   1
#define MAT_PREVIEW_MAXWELL	   2

#define SEP_STR				   "$@#&"
#define SEP_TEXTUREFILENAME	   L"@#"

#define ARGB( a, r, g, b )	   ( (COLORREF) ( ( ( (BYTE) ( b ) | ( (WORD) ( (BYTE) ( g ) ) << 8 ) ) | ( ( (DWORD) (BYTE) ( r ) ) << 16 ) ) | ( ( (DWORD) (BYTE) ( a ) ) << 24 ) ) )

#define UPDATE_NORMALS_ANGLE   60.0

using std::vector;

//------------------------------------------------------------------------------
//  Normalizing
//------------------------------------------------------------------------------

#define NORM_ERROR_1 -1
#define NORM_ERROR_2 -2
#define NORM_ERROR_3 -3
#define NORM_ERROR_4 -4
#define NORM_ERROR_5 -5
#define NORM_ERROR_6 -6
#define NORM_ERROR_7 -7

//------------------------------------------------------------------------------
typedef short Fixed16_t;
typedef long Fixed32_t;

typedef struct _OpenPointFW_t // tipo Punto con 4 coordenadas
{
	GLfloat x, y, z, w;
} OpenPointFW_t;

typedef struct _OpenPointD_t {
	double x, y, z;
} OpenPointD_t;

typedef struct _OpenPointF_t // tipo Punto con 3 coordenadas
{
	GLfloat x, y, z;
} OpenPointF_t;

typedef OpenPointF_t PointF_t;
typedef OpenPointFW_t PointFW_t;
typedef float Float_t;

typedef struct {
	PointF_t point, vector;
} OpenLineF_t;

typedef struct {
	Float_t r, g, b;
} OpenColorF_t;

typedef struct {
	Float_t r, g, b, a;
} OpenColorFA_t;

typedef struct {
	Fixed16_t r, g, b, a;
} OpenColorSA_t;

typedef OpenColorF_t ColorF_t;
typedef OpenColorFA_t ColorFA_t;
typedef OpenColorSA_t ColorSA_t;
typedef OpenLineF_t LineF_t;

using namespace InesMath;

//------------------------------------------------------------------------------

struct T3DPointExt {
	int index;
	T3DPoint point;
	bool flag;
};

//------------------------------------------------------------------------------

class TOGLFloat3;

class TOGLFloat2
{
  public:
	TOGLFloat2( )
	{
		v[ 0 ] = v[ 1 ] = 0.0;
	}
	TOGLFloat2( TOGLFloat2 *F )
	{
		Set( F );
	}
	TOGLFloat2( GLfloat f1, GLfloat f2 )
	{
		Set( f1, f2 );
	}

	void Set( TOGLFloat2 *F );
	void SetVector( GLfloat *F )
	{
		v[ 0 ] = F[ 0 ];
		v[ 1 ] = F[ 1 ];
	}
	void Set( GLfloat f1, GLfloat f2 )
	{
		v[ 0 ] = f1;
		v[ 1 ] = f2;
	}
	void SetPoint( TLPoint pt )
	{
		v[ 0 ] = pt.x;
		v[ 1 ] = pt.y;
	}
	void Set3DPoint( T3DPoint pt )
	{
		v[ 0 ] = pt.x;
		v[ 1 ] = pt.y;
	}
	TLPoint GetPoint( )
	{
		return TLPoint( v[ 0 ], v[ 1 ] );
	}
	T3DPoint Get3DPoint( )
	{
		return T3DPoint( v[ 0 ], v[ 1 ], 0.0 );
	}

	void Clear( )
	{
		v[ 0 ] = v[ 1 ] = 0.0;
	}

	double Distance( TOGLFloat2 * );
	double DistanceSqr( TOGLFloat2 * );

	TOGLFloat2 &operator=( const TOGLFloat2 &other );
	TOGLFloat2 &operator=( const TOGLFloat3 &other );

	bool operator==( const TOGLFloat2 &F );
	bool operator<( const TOGLFloat2 &F );
	bool operator>( const TOGLFloat2 &F );

	bool IsEqual( TOGLFloat2 *F, double prec = RES_COMP, bool *close = 0, double *limits = 0 );
	bool IsLess( TOGLFloat2 *F, double prec = RES_COMP );

  public:
	GLfloat v[ 2 ];
};

//------------------------------------------------------------------------------

class TOGLFloat3
{
  public:
	TOGLFloat3( )
	{
		v[ 0 ] = v[ 1 ] = v[ 2 ] = 0.0;
	}
	TOGLFloat3( TOGLFloat3 *F )
	{
		Set( F );
	}
	TOGLFloat3( GLfloat f1, GLfloat f2, GLfloat f3 )
	{
		Set( f1, f2, f3 );
	}

	void Set( TOGLFloat3 *F );
	void SetVector( GLfloat *F )
	{
		v[ 0 ] = F[ 0 ];
		v[ 1 ] = F[ 1 ];
		v[ 2 ] = F[ 2 ];
	}
	void Set( GLfloat f1, GLfloat f2, GLfloat f3 )
	{
		v[ 0 ] = f1;
		v[ 1 ] = f2;
		v[ 2 ] = f3;
	}
	void SetPoint( T3DPoint pt )
	{
		v[ 0 ] = pt.x;
		v[ 1 ] = pt.y;
		v[ 2 ] = pt.z;
	}
	void SetPointF( T3DPointF pt )
	{
		v[ 0 ] = pt.x;
		v[ 1 ] = pt.y;
		v[ 2 ] = pt.z;
	}
	T3DPoint GetPoint( )
	{
		return T3DPoint( v[ 0 ], v[ 1 ], v[ 2 ] );
	}
	T3DPointF GetPointF( )
	{
		return T3DPointF( v[ 0 ], v[ 1 ], v[ 2 ] );
	}
	void InvertAndAxisPos( TNPlane pl, bool inv, bool *chpos );

	void Clear( )
	{
		v[ 0 ] = v[ 1 ] = v[ 2 ] = 0.0;
	}

	bool operator==( const TOGLFloat3 &F );
	bool operator<( const TOGLFloat3 &F );
	bool operator>( const TOGLFloat3 &F );

	bool IsEqual( TOGLFloat3 *F, double prec = RES_COMP );
	bool IsLess( TOGLFloat3 *F, double prec = RES_COMP );

	TOGLFloat3 operator*( const GLfloat &m ) const;
	TOGLFloat3 operator+( const TOGLFloat3 &m ) const;
	TOGLFloat3 operator-( const TOGLFloat3 &m ) const;
	TOGLFloat3 &operator=( const TOGLFloat3 &other );

	bool Similar( TOGLFloat3 *, double = RES_GEOM );
	bool Similar( T3DPoint &, double = RES_GEOM );

	double Distance( TOGLFloat3 * );
	double DistanceSqr( TOGLFloat3 * );
	double Distance( T3DPoint & );
	double DistanceSqr( T3DPoint &pt );
	void Normalize( );

	void Rotate( TNPlane plane, GLfloat angle, TOGLFloat3 *center = 0 );
	void ApplyMatrix( TNMatrix *matrix );
	void ApplyMatrixXY( TNMatrix *matrix );

  public:
	GLfloat v[ 3 ];
};

//------------------------------------------------------------------------------

class TTextureSourceData
{
  public:
	TTextureSourceData( );

	void Clear( );
	void Set( TTextureSourceData * );
	bool __fastcall operator==( const TTextureSourceData &texture );
	bool IsBlendTexture( );

  public:
	int B, C, S;
	bool I, VF, HF;
	float BlendFactor;
	TColor Color;
	UnicodeString TextureName;
};

//------------------------------------------------------------------------------

typedef struct {
	int Type;
	unsigned int UID;
	UnicodeString Identifier;
	UnicodeString Value;
	UnicodeString FilePath;
	bool Visible;

} TSubstanceMatValue;

//------------------------------------------------------------------------------

class TOGLPoint;

class TOGLTexture
{
  public:
	TOGLTexture( );
	TOGLTexture( TOGLTexture *m );
	virtual ~TOGLTexture( );

	void Clear( );
	void ClearImageProperties( );
	void ClearProjectionProperties( );

	void Set( TOGLTexture *m );
	void SetBasic( TOGLTexture *m );
	void SetBasic( TOGLTexture *m, int compindex );

	void SetApplyTexture( TOGLTexture *texture );

	bool IsSameData( TOGLTexture *texture );
	bool IsBCSHDefault( );

	bool IsValid( );
	bool IsNull( );
	bool IsIDUsed( int id );
	void ClearID( int compindex = 0 );
	void ClearUsed( int compindex = 0 );

	UnicodeString GetRealName( );
	UnicodeString GetMaxwellSecondaryRealName( );
	bool Download( bool force, int compindex = 0 );

	void ApplyOGLParameters( int compindex, int width, int height, GLubyte *rgb );

	void CopyMaterialsToPath( UnicodeString *orgpath, UnicodeString *newpath, bool force = true, UnicodeString *orgpathtexturesUV = 0 );

	bool __fastcall operator==( const TOGLTexture &texture );

  public:
	UnicodeString Name;	  // Si existe fichero asociado a la imagen
	UnicodeString SubDir; // Subdirectorio donde se encuentra el fichero de imagen

	bool MaxwellSecondaryActive; // Textura secundaria de Maxwell activa para su edicion. Temporal, no se almacena
	UnicodeString MaxwellSecondaryName;
	UnicodeString MaxwellSecondarySubDir;

	int ID[ MAX_NUM_TEXTURE_COMPILATIONS ];
	bool IsUsed[ MAX_NUM_TEXTURE_COMPILATIONS ];
	bool ApplyTexture;
	int Width, Height, OrgWidth, OrgHeight; // Pixels
	double Resolution;						// Pixels por pulgada
	float bumpIntensity;					// Intensidad del relieve

	int MagFilter; // GL_LINEAR, GL_NEAREST, GL_LINEAR_MIPMAP_LINEAR
	int MinFilter;

	HDC hOGLDC[ MAX_NUM_TEXTURE_COMPILATIONS ];	  // Device Context del dispositivo de dibujado
	HGLRC hOGLRC[ MAX_NUM_TEXTURE_COMPILATIONS ]; // Render Context en donde se guardaran las listas

	// Image properties
	bool Invert;
	float Hue, Brightness, Contrast, Saturation;

	// Projection properties
	bool Mirror[ 2 ];
	float Repeat[ 2 ], Offset[ 2 ], Rotation;
};

//------------------------------------------------------------------------------

class TOGLTextureData;
class TOGLTextureDataList
{
  public:
	TOGLTextureDataList( );
	~TOGLTextureDataList( );

	void Clear( );
	int Count( );
	void Grow( int d );

	void Set( TOGLTextureDataList * );
	void Init( int nitems, int curitem );

	void AddItem( TOGLTextureData *ogltexdata );
	void SetItem( int ind, TOGLTextureData *ogltexdata );
	void InsertItem( int ind, TOGLTextureData *ogltexdata );
	void DelItem( int ind );
	TOGLTextureData *GetItem( int ind );
	void ReplaceItems( int ind1, int ind2 );

	virtual int GetCurrentIndex( );
	virtual void SetCurrentIndex( int );
	virtual TOGLTextureData *GetCurrentItem( );

	void SetForceCenter( bool value, int index = -1 ); // si es -1 se pone a todos los ogltexturedata

	bool __fastcall operator==( const TOGLTextureDataList &ogltexdatalist );

  public:
	int numItems, maxItems, curItem;
	TOGLTextureData *Item;
};

//------------------------------------------------------------------------------

class TOGLMaterial;

class TOGLTextureList
{
  public:
	TOGLTextureList( );
	virtual ~TOGLTextureList( );

	void Set( TOGLTextureList *E );

	void AddItem( TOGLTexture *s );
	void SetItem( int ind, TOGLTexture *s );
	void DelItem( int ind );
	void DetachItem( TOGLTexture * );
	TOGLTexture *GetItem( int ind );
	TOGLTexture *GetItemByMaterial( TOGLMaterial *material, int *index = 0, bool alltextures = false );
	TOGLTexture *GetItemByTexture( TOGLTexture *ogltextureorg, UnicodeString *pathuv );
	UnicodeString GetName( int ind );
	UnicodeString GetNewName( UnicodeString *str = 0 );
	UnicodeString GetSubDir( int ind );

	UnicodeString GetPathOwnTexturesUV( );
	UnicodeString GetCurrentPathTexturesUV( );
	void UpdatePathOwnMaterials( UnicodeString *newpath );

	void Clear( int max = 10 );
	void ClearID( int compindex = 0 );
	void ClearUsed( int compindex = 0 );

	int Count( );
	void Grow( int d );
	void OrderList( );

	bool Read( UnicodeString path );

	int AddCompilation( );

	bool __fastcall operator==( const TOGLTextureList &list );

  public:
	int numItems, maxItems;
	TOGLTexture *Item;

	int numCompilations;
	int TexturesType;
	UnicodeString PathOwnTexturesUV;
};

//------------------------------------------------------------------------------

class TMaterialCategory
{
  public:
	TMaterialCategory( )
	{
		Key = Name = Description = Tags = "";
	}

  public:
	UnicodeString Key;
	UnicodeString Name;
	UnicodeString Description;

	UnicodeString Tags;
};

//------------------------------------------------------------------------------
class TMXM_Data;
class TOGLPerspData;

class TOGLMaterial
{
  public:
	TOGLMaterial( );
	TOGLMaterial( TOGLMaterial *m );
	~TOGLMaterial( );

	void InitMxmDataType( );
	void Set( TOGLMaterial *m );
	void Clear( );

	bool IsValid( )
	{
		return !Name.IsEmpty( );
	}
	bool IsBOMValid( bool forcereferences )
	{
		return ( !forcereferences || !Reference.IsEmpty( ) );
	}
	bool IsReady( )
	{
		return isReady;
	}

	void Apply( GLenum face = GL_FRONT_AND_BACK );

	void SetColor( TColor c );
	void SetColorAndRefreshSpecular( TColor c );
	TColor GetColor( );
	TColorRec GetColorRec( );
	TAlphaColor GetAlphaColor( );
	void LightColor( );

	void SetTransparent( bool b );
	void SetTransparent( double value );
	bool IsTransparent( );
	bool IsTranslucent( float *roughness = 0 );

	void SetBlendFactor( float bf )
	{
		TSD.BlendFactor = bf;
	}
	float GetBlendFactor( )
	{
		return TSD.BlendFactor;
	}

	bool IsSameData( TOGLMaterial *material );
	bool IsSameBasicData( TOGLMaterial *material, bool checkPathOwn = true, bool basicname = false );
	bool IsSameBOMData( TOGLMaterial *material );
	bool IsPBRDefault( );
	bool IsNeededToEditMap( int id );

	int GetMapEdited( int mapType, TdxSmartImage **image, bool onlytex = false, int finalwidth = 0, int maxTextureSize = -1 );
	int GetMapBase( int mapType, TdxSmartImage **image, int maxTextureSize = -1 );
	int WriteMapEdited( int mapType, UnicodeString dstfile, bool onlytex = false, int finalwidth = 0, int maxTextureSize = -1 );
	int WriteMapBase( int mapType, UnicodeString dstfile, int maxTextureSize = -1 );

	TSize GetMapBaseSize( int mapType );

	bool HasPBRTexture( );
	TOGLTexture *GetCurrentOGLTexture( int *id = 0 );
	void SetTexturesSubDir( UnicodeString subdir );
	TOGLTexture *GetPBRTexture( int i );

	UnicodeString GetBasicName( int *type = 0 );
	UnicodeString GetActiveTextureSubDir( );
	UnicodeString GetActiveTextureName( );
	void ChangeResolution( double res );
	void CheckApplyEffect( );

	void EraseMaxwellData( );

	TdxSmartImage *GetMaterialImage_v2( UnicodeString previewModel, int width, int height, int *viewport = 0, double *proj = 0, double *modelview = 0, TOGLPerspData *perspData = 0, bool transparent = true );
	TdxSmartImage *GetMaterialImage( UnicodeString previewModel, int width, int height, double zoom = 1.0, TLPoint origin = TLPoint( 0.0, 0.0 ), double repeat = 1.0, bool transparent = true );

	void SetDataXML( TOGLMaterial *oglmat );
	bool WriteDataXML( UnicodeString file );
	bool WriteDataXML( _di_IXMLNode xmlNode );
	bool ReadDataXML( UnicodeString file );
	bool ReadDataXML( _di_IXMLNode xmlNode );
	bool ReadXML( UnicodeString file, UnicodeString library );

	bool WriteU3M( UnicodeString file, bool zipFile = true, bool potImages = false, int maxTextureSize = -1 );
	bool WriteSHM( UnicodeString pathmaterials, UnicodeString shmfile = EmptyStr, bool removemaxwellinfo = false );
	void Write( UnicodeString material_path, UnicodeString strindex = EmptyStr, TMemIniFile *_local_file = 0 );
	void UpdateMaterialMTR( UnicodeString *pathroot );
	bool Read( UnicodeString material_path, UnicodeString material, bool updateBlendMode = true, UnicodeString strindex = EmptyStr, TMemIniFile *_local_file = 0 );
	bool Read( UnicodeString *currentpath, UnicodeString *matnameOrig, UnicodeString *librarynameOrig, bool hasTexture, UnicodeString *tmpbitmapname = 0, bool checkexists = false );
	void InitTextureImageMat( int value = 242 );
	bool IsObsoleteDefTextureMat( );
	void ReadDefTextureMat( UnicodeString *tmpPathToRead = 0 );
	void SaveDefTextureMat( UnicodeString *tmpPathToRead = 0 );

	void ReadSubstanceSBSPRS( UnicodeString subsFile );
	void WriteSubstanceSBSPRS( UnicodeString subsFile );

	void InitSubstanceValues( );
	std::map<unsigned int, TSubstanceMatValue> *GetSubstanceValues( )
	{
		return SubstanceValues;
	}
	void CopySubstanceAuxFiles( UnicodeString oldlibrary, UnicodeString oldname, bool omitSbsar = false );
	void CopyTexturesForSubstance( UnicodeString newpath, UnicodeString newlibrary, UnicodeString newbasicname );

	void CopyMaterialsToPath( UnicodeString *newpath, bool force = true, bool checktexture = true, bool cancopymaxwell = true, bool checkduplicated = false, bool force2DMat = false, UnicodeString *errormsg = 0, UnicodeString *_newbasicname = 0, UnicodeString *_newlibrary = 0 );
	void UpdatePathOwnMaterials( UnicodeString *newpath );
	void CheckPathOwnMaterials( UnicodeString *newpath, bool checktexture = true );
	void ClearMaterialsFromPath( );

	UnicodeString GetPathOwnSimpleMaterialsLibrary( );
	UnicodeString GetCurrentPathSimpleMaterialsLibrary( );
	UnicodeString GetCurrentPathTextures( );
	UnicodeString GetCurrentPathMaxwellTextures( );
	UnicodeString GetCurrentPathEffects( );

	UnicodeString GetPathBitmap( bool hasTexture );
	TcxBitmap *GetBitmap( int finalHeight, bool hasTexture, int forcefinalwidth = 0 );
	TdxSmartImage *GetImage( int finalHeight, bool hasTexture, int forcefinalwidth = 0 );

	bool AdjustMaxwellTexture( UnicodeString *filename, double xscale, double yscale, bool linkedTextureMapping );
	bool GetTextureDataOfMaxwellTexture( UnicodeString *filename, double &utile, double &vtile, double &uoffset, double &voffset, double &xscale, double &yscale, double &umirror, double &vmirror );

	bool __fastcall operator==( const TOGLMaterial &material );

	//		void InitSubstanceData( );

  public:
	UnicodeString GUID;
	TDateTime CreationDate;
	TDateTime EditionDate;

	UnicodeString Name;
	UnicodeString Library;

	UnicodeString PathOwnSimpleMaterialsLibrary;

	// Datos adicionales------------
	// Propiedades
	UnicodeString Reference;
	UnicodeString DisplayName;
	UnicodeString Description;
	UnicodeString ColorReference;
	UnicodeString Supplier;
	int ConsumptionType;
	int LinearUnit, QuadraticUnit, CubicUnit;
	double Density;
	double CarbonFootprint;
	double Price;
	UnicodeString Currency;

	// Etiquetas
	TLabelsData Labels;

	// Categorias y tags
	std::map<UnicodeString, TMaterialCategory> TagCategories;
	UnicodeString PlatformCategories;
	//------------------------------

	bool isReady; // Material listo con valores correctos
	bool isLocked;

	int PreviewType; // VIRTUAL, PBR, MAXWELL
	UnicodeString PreviewModel;
	float PreviewZoom;

	// Datos basicos
	float Shininess;	// 0..128
	ColorFA_t Ambient;	// 0..1 cada componente
	ColorFA_t Diffuse;	// 0..1 cada componente
	ColorFA_t Specular; // 0..1 cada componente
	TTextureSourceData TSD;

	TOGLTexture Texture; // Corresponde a DiffuseMap( BASIC ) AlbedoMap( PBR )

	// Datos para efectos
	bool ApplyEffect;
	int FusionMode, EffResolution, EffOpacity, EffInv;
	UnicodeString FilterRoute;

	// Datos PBR
	bool MixAlbedoWithColor;
	float MixAlbedoFactor;

	bool UseNormalMap;
	TOGLTexture *NormalMap;
	bool FlipNormalX, FlipNormalY;
	float StrengthNormal; // 0..5 - 1

	bool UseMetallicMap;
	TOGLTexture *MetallicMap;
	float Metallic; // 0..1 - 0

	bool UseRoughnessMap;
	TOGLTexture *RoughnessMap;
	float Roughness; // 0..1 - 1

	bool UseAOMap;
	TOGLTexture *AOMap;
	float AO; // 0..1 - 1

	bool UseOpacityMap;
	TOGLTexture *OpacityMap;
	float Opacity;			// 0..1 - 1
	float OpacityRoughness; // 0..1 - 0

	bool UseDisplacementMap;
	TOGLTexture *DisplacementMap;
	float StrengthDisplacement; // 0..5 1

	// Datos para maxwell
	bool IsMaxwell;
	int MaxwellType;
	TMXM_Data *MaxwellData;

	// Datos para substance;
	bool IsSubstance;
	UnicodeString SbsarFileName;
	UnicodeString SubstancePkgurl;
	std::map<unsigned int, TSubstanceMatValue> *SubstanceValues;
};

//------------------------------------------------------------------------------

class TOGLPointerMaterialList
{
  public:
	TOGLPointerMaterialList( );
	virtual ~TOGLPointerMaterialList( );

	virtual void Clear( int items = 10 );

	virtual void AddItem( TOGLMaterial *td );
	virtual void SetItem( int ind, TOGLMaterial *td );
	virtual void DelItem( TOGLMaterial *td = 0 ); // 0 borra el ultimo
	virtual TOGLMaterial *GetItem( int ind );

	virtual int Count( );
	virtual void Grow( int d );

  protected:
	int numItems, maxItems;
	TOGLMaterial **Item;
};

//------------------------------------------------------------------------------

class TOGLMaterialList
{
  public:
	TOGLMaterialList( );
	virtual ~TOGLMaterialList( );

	void Set( TOGLMaterialList *E );

	void SetMainIndex( int i );
	int GetMainIndex( )
	{
		return MainIndex;
	}
	TOGLMaterial *GetMainMaterial( );

	void AddItem( TOGLMaterial *s );
	void SetItem( int ind, TOGLMaterial *s );
	void DelItem( int ind );
	TOGLMaterial *GetItem( int ind );
	TOGLMaterial *GetItem( UnicodeString *_library, UnicodeString *_name, UnicodeString *pathownsimplematerialslibrary = 0, int *index = 0, bool usepathown = true );
	int GetItemIndex( TOGLMaterial *s );
	UnicodeString GetName( int ind );

	bool IsSameBasicData( TOGLMaterialList *materiallist );

	void Clear( );
	int Count( );
	void Grow( int d );
	void OrderList( );

	void CopyMaterialsToPath( UnicodeString *newpath, bool force = true, bool checktexture = true, bool cancopymaxwell = true, bool force2DMat = false );
	void UpdatePathOwnMaterials( UnicodeString *newpath );
	void CheckPathOwnMaterials( UnicodeString *newpath );

	bool Write( UnicodeString *list_path );
	bool Read( UnicodeString *list_path, UnicodeString *mat_path, vector<UnicodeString> *notFoundedMaterials = 0 );
	bool Read( UnicodeString *path, UnicodeString *material_path, UnicodeString *material, TOGLMaterialList * );

  public:
	UnicodeString Name;
	UnicodeString Library;
	int MainIndex; // Indice del material principal

	int numItems, maxItems;
	TOGLMaterial *Item;
};

//------------------------------------------------------------------------------

class TOGLMaterialListList
{
  public:
	TOGLMaterialListList( );
	~TOGLMaterialListList( );

	void Clear( );
	int Count( );
	void Grow( int d );

	void Set( TOGLMaterialListList * );
	void Init( int nitems, int curitem );

	void AddItem( TOGLMaterialList *s );
	void SetItem( int ind, TOGLMaterialList *s );
	void InsertItem( int ind, TOGLMaterialList *s );
	void DelItem( int ind );
	TOGLMaterialList *GetItem( int ind );
	void ReplaceItems( int ind1, int ind2 );

	virtual int GetCurrentIndex( );
	virtual void SetCurrentIndex( int );
	virtual TOGLMaterialList *GetCurrentItem( );

	virtual void CopyMaterialsToPath( UnicodeString *newpath, bool force = true, bool checktexture = true, bool cancopymaxwell = true, bool force2DMat = false );
	virtual void UpdatePathOwnMaterials( UnicodeString *newpath );
	virtual void CheckPathOwnMaterials( UnicodeString *newpath );

  public:
	int numItems, maxItems, curItem;
	TOGLMaterialList *Item;
};

//------------------------------------------------------------------------------

class TOGLMaterialExt
{
  public:
	TOGLMaterialExt( );

	void Set( TOGLMaterialExt *S );

	bool __fastcall operator==( const TOGLMaterialExt &ogl );

  public:
	bool Stipple;			 // Activar patron rayado
	int StippleFactor;		 // Factor del patron
	GLushort StipplePattern; // Patron rayado

	TOGLMaterial Material[ 2 ]; // Materiales sin textura: FRONT y BACK
};

//------------------------------------------------------------------------------

class TOGLMaterialExtList
{
  public:
	TOGLMaterialExtList( );
	virtual ~TOGLMaterialExtList( );

	void Set( TOGLMaterialExtList *E );

	void AddItem( TOGLMaterialExt *s );
	void SetItem( int ind, TOGLMaterialExt *s );
	void DelItem( int ind );
	TOGLMaterialExt *GetItem( int ind ) const;

	void Clear( );
	int Count( ) const;
	void Grow( int d );

	bool __fastcall operator==( const TOGLMaterialExtList &ogl );

  public:
	int numItems, maxItems;
	TOGLMaterialExt *Item;
};

//------------------------------------------------------------------------------

class TLight
{
  public:
	TLight( );
	void Set( TLight *light );
	void SetPosAndDir( TLight *light );
	void SetDefaultFocalData( );
	void SetColor( TColor c );
	TColor GetColor( );
	bool IsOmnidirectional( );
	bool IsSpotLight( );
	bool IsDirectional( );
	bool IsDirLightPBRDirectional( )
	{
		return ( DirLightType == DIRLIGHT_TYPE_PBR_DIRECTIONAL );
	}
	bool IsDirLightPBRSpot( )
	{
		return ( DirLightType == DIRLIGHT_TYPE_PBR_SPOT );
	}
	bool IsDirLightPBRPoint( )
	{
		return ( DirLightType == DIRLIGHT_TYPE_PBR_POINT );
	}
	void SetDirection( T3DPoint p );
	T3DPoint GetDirection( );
	void SetPosition( T3DPoint p );
	T3DPoint GetPosition( );
	bool Read( UnicodeString light_file, UnicodeString light, int i, TMemIniFile *_local_file = 0 );
	void Write( UnicodeString file, int i, TMemIniFile *_local_file = 0 );
	bool operator==( const TLight &l ) const;
	bool operator!=( const TLight &l ) const;

  public:
	UnicodeString Name;
	bool Enabled;

	ColorFA_t Ambient;
	ColorFA_t Diffuse;
	ColorFA_t Specular;
	PointFW_t Position;

	PointF_t SpotDir;
	PointF_t OrigDirectional;
	T3DPoint TargetPoint;
	double SpotCutoff;
	double SpotExponent;
	double ConstAtt;
	double LinearAtt;
	double QuadrAtt;

	bool ShadowEnabled;
	double ShadowIntensity;
	int MovementType;

	bool LinkedToHDR;
	bool UseShadows;
	float ShadowsBias; // 0..1

	int DirLightType; // Se utiliza para saber el tipo a asignar a la linea de tipo dirlight asociada a la luz. Deben ir de la mano
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void NormalizePoint( GLfloat &x, GLfloat &y, GLfloat &z );

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Clases para el tratamiento de pol?nos obtenido de la triangularizaci??e
// superficies
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class TOGLPoint
{
	friend class TImpExp_XML;

  public:
	TOGLPoint( )
	{
	}
	TOGLPoint( TOGLFloat3 *_v, TOGLFloat2 *_uv, TOGLFloat3 *_n, TOGLFloat2 *_t )
	{
		Set( _v, _uv, _n, _t );
	}

	void Set( TOGLPoint *F );
	void Set( TOGLFloat3 *_v, TOGLFloat2 *_uv, TOGLFloat3 *_n, TOGLFloat2 *_t );

	void Clear( );

	bool operator==( const TOGLPoint &F );
	bool operator<( const TOGLPoint &F );
	bool operator>( const TOGLPoint &F );

	bool IsEqual( TOGLPoint *F, double prec = RES_COMP, int *CompareMask = 0, bool *close = 0, double *limits = 0 );
	bool IsLess( TOGLPoint *F, double prec = RES_COMP, int *CompareMask = 0 );

	void ApplyMatrix( TNMatrix *matrix, bool usenormals );

  public:
	TOGLFloat3 v;
	TOGLFloat2 uv;
	TOGLFloat3 n;
	TOGLFloat2 t;
};

//------------------------------------------------------------------------------

struct TOGLPointExt {
	TOGLPoint data;
	struct TOGLPointExt *next;
};

//------------------------------------------------------------------------------
// Clases para la gesti??e un ?ol binario. Se har?en?co
// De momento lo tenemos instanciado a TOGLPoint

class TOGLBTKey
{
  public:
	TOGLPoint Item;
	int Index;
	TOGLBTKey( );
	virtual ~TOGLBTKey( );
};

class TOGLBTree;

class TOGLBTNode
{
	friend class TOGLBTree;

  public:
	TOGLBTNode( TOGLBTNode *parent, short int Dim, bool leaf = true, int comparemask = CMASK_ALL );
	~TOGLBTNode( );
	int Insert( TOGLPoint *item, const int &index, TOGLPoint *equalitem = 0, double prec = RES_COMP );

  private:
	TOGLBTNode *Parent;
	short int Count, Dimension;
	TOGLBTree *Tree;
	TOGLBTKey *Keys;
	TOGLBTNode **Branch;
	bool IsLeaf;
	int CompareMask;

	void SplitLeaf( TOGLPoint *item, const int &index, const int &newpos );
	void SplitNoLeaf( TOGLPoint *item, const int &index, const int &newpos, TOGLBTNode *leftBranch, TOGLBTNode *rightBranch );
	void Spread( TOGLPoint *item, const int &index, TOGLBTNode *leftBranch, TOGLBTNode *rightBranch );
};

class TOGLBTree
{
  public:
	TOGLBTree( short int Dim, int comparemask = CMASK_ALL );
	~TOGLBTree( );

	int Insert( TOGLPoint *it, TOGLPoint *equalitem = 0, double prec = RES_COMP );
	int GetCount( )
	{
		return Count;
	}

  public:
	TOGLBTNode *Root;

  private:
	int Count;
};

//------------------------------------------------------------------------------

class TOGLBTKeyFloat2
{
  public:
	TOGLFloat2 Item;
	int Index;
	TOGLBTKeyFloat2( );
	virtual ~TOGLBTKeyFloat2( );
};

class TOGLBTreeFloat2;

class TOGLBTNodeFloat2
{
	friend class TOGLBTreeFloat2;

  public:
	TOGLBTNodeFloat2( TOGLBTNodeFloat2 *parent, short int Dim, bool leaf = true );
	~TOGLBTNodeFloat2( );
	int Insert( TOGLFloat2 *item, const int &index, TOGLFloat2 *equalitem = 0, double prec = RES_COMP );

  private:
	TOGLBTNodeFloat2 *Parent;
	short int Count, Dimension;
	TOGLBTreeFloat2 *Tree;
	TOGLBTKeyFloat2 *Keys;
	TOGLBTNodeFloat2 **Branch;
	bool IsLeaf;

	void SplitLeaf( TOGLFloat2 *item, const int &index, const int &newpos );
	void SplitNoLeaf( TOGLFloat2 *item, const int &index, const int &newpos, TOGLBTNodeFloat2 *leftBranch, TOGLBTNodeFloat2 *rightBranch );
	void Spread( TOGLFloat2 *item, const int &index, TOGLBTNodeFloat2 *leftBranch, TOGLBTNodeFloat2 *rightBranch );
};

class TOGLBTreeFloat2
{
  public:
	TOGLBTreeFloat2( short int Dim );
	~TOGLBTreeFloat2( );

	int Insert( TOGLFloat2 *it, TOGLFloat2 *equalitem = 0, double prec = RES_COMP );
	int GetCount( )
	{
		return Count;
	}

  public:
	TOGLBTNodeFloat2 *Root;

  private:
	int Count;
};

//------------------------------------------------------------------------------

class TOGLBTKeyFloat3
{
  public:
	TOGLFloat3 Item;
	int Index;
	TOGLBTKeyFloat3( );
	virtual ~TOGLBTKeyFloat3( );
};

class TOGLBTreeFloat3;

class TOGLBTNodeFloat3
{
	friend class TOGLBTreeFloat3;

  public:
	TOGLBTNodeFloat3( TOGLBTNodeFloat3 *parent, short int Dim, bool leaf = true );
	~TOGLBTNodeFloat3( );
	int Insert( TOGLFloat3 *item, const int &index, TOGLFloat3 *equalitem = 0, double prec = RES_COMP );

  private:
	TOGLBTNodeFloat3 *Parent;
	short int Count, Dimension;
	TOGLBTreeFloat3 *Tree;
	TOGLBTKeyFloat3 *Keys;
	TOGLBTNodeFloat3 **Branch;
	bool IsLeaf;

	void SplitLeaf( TOGLFloat3 *item, const int &index, const int &newpos );
	void SplitNoLeaf( TOGLFloat3 *item, const int &index, const int &newpos, TOGLBTNodeFloat3 *leftBranch, TOGLBTNodeFloat3 *rightBranch );
	void Spread( TOGLFloat3 *item, const int &index, TOGLBTNodeFloat3 *leftBranch, TOGLBTNodeFloat3 *rightBranch );
};

class TOGLBTreeFloat3
{
  public:
	TOGLBTreeFloat3( short int Dim );
	~TOGLBTreeFloat3( );

	int Insert( TOGLFloat3 *it, TOGLFloat3 *equalitem = 0, double prec = RES_COMP );
	int GetCount( )
	{
		return Count;
	}

  public:
	TOGLBTNodeFloat3 *Root;

  private:
	int Count;
};

//------------------------------------------------------------------------------

class SISLSurf;
class TOGLTransf; // Forward declarations
class TOffsetVarData;
class TPaddingData;
class TNDoublesList;
class TCadEntity;
class TCadSurface;
class TCadIBSpline;
class TCadPolyline;
class TOGLPolygonList;
class TParallelData;
class TParallelTypeData;
class TInteger_List;
class TInteger_ListList;
class T3DPolygon;
class TInstanceList;
class IwTree;

class TOGLPolygon
{
  public:
	TOGLPolygon( int d = DEFAULT_DITEMS_POL );
	TOGLPolygon( GLenum t, int d, bool n = false, bool tx = false );
	TOGLPolygon( TOGLPolygon *Pol, bool adjustmaxsize = false );
	virtual ~TOGLPolygon( );

	void SetType( GLenum t )
	{
		type = t;
	}
	GLenum GetType( )
	{
		return type;
	}

	void SetUseNormals( bool b )
	{
		usenormals = b;
	}
	bool GetUseNormals( )
	{
		return usenormals;
	}
	void SetUVFromV( bool clearv = true );
	void SetUVFromT( );
	void SetVFromUV( bool clearuv = true );
	void SetVFromT( );
	void SetTFromV( );
	void SetUseTextures( bool b )
	{
		usetextures = b;
	}
	bool GetUseTextures( )
	{
		return usetextures;
	}

	void Set( TOGLPolygon *Pol );
	void Set( T3DPolygon *Pol );
	void SetUV( TOGLPolygon *Pol );
	void SetT( TOGLPolygon *Pol );
	void SetPoints( int np, TOGLPoint *pts );
	void AppendPoints( int np, TOGLPoint *pts );
	void Append( TOGLPolygon *Pol );
	void SetVertexs( int np, T3DPoint * );
	void SetVertexs( T3DRect r );
	T3DPoint *GetVertexs( int &np );
	T3DPoint *GetVertexsUV( int &np );
	TOGLPoint *GetOGLPoints( int &np );
	GLfloat *GetPWLPoints( int &np );
	bool SameVertexs( TOGLPolygon *pol );
	bool IsHomogeneous( TOGLPolygon *pol );

	void Clear( bool = false );
	void ClearUV( );
	void ClearT( );

	void GrowItems( long d = 0 );
	void AdjustSize( long dB = 0 );
	int GetIndexToAdd( T3DPoint pt );
	void AddItem( TOGLPoint *p, int ind = -1 );
	void AddItem( T3DPoint *p3D, int ind = -1 );
	void AddItemTol( TOGLPoint *p, double tolerance );
	void SetItem( int ind, TOGLPoint *p );
	void DeleteItem( int ind, int num = 1 );
	TOGLPoint *GetItem( int ind );
	TOGLPoint *GetFirstItem( );
	TOGLPoint *GetLastItem( );
	int Count( )
	{
		return numItems;
	}
	long GetMaxItems( )
	{
		return maxItems;
	}

	bool GetSubItem( TOGLPolygon *Pol, int first, int last, double tol = RES_GEOM2, bool erase = true, int delta = 1 );
	bool GetSubItem( long lim1, long lim2, TOGLPolygon *Pol );
	bool GetSubItem( double pct1, double pct2, bool checkclose, bool *close, double *limits, TOGLPolygon *Pol );
	bool GetSubItem( int ind1, double pct1, int ind2, double pct2, bool checkclose, bool *close, double *limits, TOGLPolygon *Pol );

	bool AreContinuous( TOGLPolygon *pol, bool checkclose = false, bool *close = 0, double *limits = 0, bool uv = false );
	bool IsCloseExt( bool checkclose = false, bool *close = 0, double *limits = 0, bool uv = false );
	bool IsClockwiseUV( );
	bool MustInvertClockwiseXY( bool checkplane = false );
	void ConvertPolygonToTriangles( TOGLTransf *OGLTransf, bool keept = false, double precDeletePts = RES_COMP, bool canAddBoundaryPts = false, bool updateuvfromv = false );
	void ConvertQuadStripsToQuads( );
	void DivideTriangles( TOGLPolygonList *out, double maxlength2 );
	T3DPoint GravityCenter( );
	T3DPoint GravityCenter( double inc );
	bool GetYZMatrix( TNMatrix &mat, TNMatrix &mati );
	double Perimeter( bool closed = false );
	double PerimeterSegment( int ind1, int ind2 );
	double PerimeterSegment( double pct1, double pct2 );
	double GetRelatedDistance( TOGLPolygon *pol, double dist );
	float SignedArea( TNPlane plane );
	bool Contains( TOGLFloat3 *p );

	void GetFarestIndexes( int &index, int &index2 );
	void GetFarestPointsByAxis( T3DPoint &ptMin, T3DPoint &ptMax, char axis );

	double GetNearestVertex( TOGLFloat3 *v, bool checkparam, bool *close, double *limits, int &, TOGLFloat3 & );
	bool GetNearestPoint( TOGLFloat3 *v, T3DPoint &pt );
	double GetNearestVertexX( TOGLFloat3 *v, int &, TOGLFloat3 & );
	int FindNearestPointYZ( TOGLFloat3 *p );
	double FindNearestPoint( TOGLFloat3 *p, TOGLFloat3 &nearest, bool bApplySqrtToDistance = false );
	int GetNearestPointContYZ( TOGLFloat3 *P, TOGLFloat3 &Point );
	double GetPolNearestVertex( TOGLPolygon *Pol, bool checkparam, bool *close, double *limits, int &ind, TOGLFloat3 &vertex );
	double GetPolNearestVertex( TOGLPolygon *Pol, double res, TOGLFloat3 &vertex, TOGLFloat3 &vertex2 );

	void GetPerimeterIndexPct( double dist, int &index, double &pct );
	void GetVertexIndexPct( TOGLFloat3 *, int &, double &, bool checkdist = true );
	void GetVertexUVIndexPct( TOGLFloat2 *, int &, double & );

	bool GetPointByIndexPct( int index, double pct, bool, bool *close, double *limits, T3DPoint & );
	bool GetVertexByIndexPct( int index, double pct, bool, bool *close, double *limits, TOGLFloat3 *v );
	bool GetVertexUVByIndexPct( int, double, bool, bool *close, double *limits, TOGLFloat2 * );
	bool GetItemByIndexPct( int, double, bool, bool *close, double *limits, bool uv, TOGLPoint * );
	double GetPctByIndexPct( int ind, double pct, double per = -1.0 );

	bool GetVertexFromPct( double pct, double p, TOGLFloat3 *v );
	bool GetPointAndNormalFromPct( double pct, double p, T3DPoint &pt, T3DPoint &n, double dist = 1.0, T3DPoint axis = T3DPoint( 0.0, 0.0, 1.0 ), bool checkclose = false, bool *close = 0, double *limits = 0, int extendside = EXTEND_BOTH );
	bool GetAllFromPct( double pct, double p, TOGLFloat3 *v, int &, double & );
	bool GetPointsAndOrientedNormalsFromPcts_Closed( TOGLTransf *OGLTransf, TCadSurface *surf, TOGLPolygon *_PolParam, int npcts, double *pcts, bool inside, TOGLPolygon *points, double dist = 1.0, int extendside = EXTEND_BOTH );

	bool GetVertexFromIndexDist( int index, double dist, bool isclose, TOGLFloat3 *v );
	bool GetNormalFromIndex( int index, T3DPoint &n, double dist = 1.0, T3DPoint axis = T3DPoint( 0.0, 0.0, 1.0 ), bool isclose = false, bool forcebackward = false, bool forceforward = false );
	bool GetPointsAndOrientedNormalsFromIndexes_Closed( TOGLTransf *OGLTransf, TCadSurface *surf, TOGLPolygon *_PolParam, bool inside, TOGLPolygon *points, double dist = 1.0 );

	double *GetPcts( double per = -1.0 );
	double GetPct( int ind, double per );
	double GetPct( TOGLFloat3 *, double per, int *vtxind = 0, double *vtxpct = 0 );
	double GetPctFromRaster( TOGLTransf *OGLTransf, TPoint point, double per = 0.0, int wndheight = -1, TOGLFloat3 *outvtx = 0 );

	bool Difference( T3DPlane *plane, TOGLPolygonList *out, TOGLPolygonList *out2 = 0 );
	bool Difference( TOGLTransf *OGLTransf, TCadSurface *surf, TOGLPolygonList *out, TOGLPolygonList *out2 = 0 );

	void IntersectSegmentUV( int, int, TOGLPolygon *Pol, TOGLPolygon *Out );
	void IntersectUV( TOGLPolygon *Pol, TOGLPolygon *Out );
	void IntersectSegment( int ind1, int ind2, TOGLPolygon *Pol, TOGLPolygon *Out, TOGLPolygon *Out2, TNPlane plane = plXY, bool checkclose = false, bool *close = 0 );
	bool IntersectSegments( int ind1_1, int ind1_2, int ind2_1, int ind2_2, TOGLPoint *out, TNPlane plane = plXY );
	void Intersect( TOGLPolygon *Pol, TOGLPolygon *Out, TOGLPolygon *Out2 = 0, TNPlane plane = plXY, double extenddist = 0.0, bool checkclose = false, bool *close = 0, bool clear = true, double similardist = RES_GEOM );
	bool Intersect( T3DPlane &plane, TOGLPolygon *res, TOGLPolygon *ind, bool adduv = true, bool addnor = true, bool addtex = true );
	void IntersectXY( TOGLPolygon *Pol, TOGLPolygon *Out, TOGLPolygon *Out2 = 0, double extenddist = 0.0, bool checkclose = false, bool *close = 0, bool clear = true, double similardist = RES_GEOM );
	void IntersectXZ( TOGLPolygon *Pol, TOGLPolygon *Out, TOGLPolygon *Out2 = 0, double extenddist = 0.0, bool clear = true );
	void IntersectYZ( TOGLPolygon *Pol, TOGLPolygon *Out, TOGLPolygon *Out2 = 0, double extenddist = 0.0, bool clear = true );
	void IntersectItself( TOGLPolygon *Out, TNPlane plane = plXY );
	bool IntersectItselfXY( TOGLPolygon *Out = 0 );
	bool CheckIntersectXY( TOGLPolygon *Pol, T3DRect *r1 = 0, T3DRect *rpol = 0 );
	void Divide( TOGLPolygonList *in, TOGLPolygonList *out, bool orderbyin = true, TInteger_List *extrems = 0 );
	bool GetIntersectRange( TOGLPolygon *Pol, double &pct1, double &pct2, TNDoublesList *segments = 0, bool excludeholes = false );

	bool FitToRect( TOGLTransf *, T3DPoint, T3DPoint, TCadEntity * = 0, bool force = false );
	void Move( T3DPoint );
	void MoveX( double incr );
	void MoveY( double incr );
	void MoveFromTo( T3DPoint org, T3DPoint dst );
	void Scale( T3DPoint );
	void ApplyMatrix( TNMatrix *matrix, bool checkusenormals = true );
	void ApplyMatrixXY( TNMatrix *matrix );
	void RotateXY( T3DPoint center, double Angle, bool rad = false, double *sinangle = 0, double *cosangle = 0 );
	void HMirror( TOGLFloat3 *m, TOGLFloat3 *M, TNPlane plane, bool inverted );
	void VMirror( TOGLFloat3 *m, TOGLFloat3 *M, TNPlane plane, bool inverted );
	void MirrorX0( bool invert = true );
	void MirrorY0( bool invert = true );
	void SymAxis( T3DPoint p1, T3DPoint p2 );
	void SymPlane( T3DPlane plane );
	void RevertSecondDevelopSurfIndex( TOGLTransf *OGLTransf, bool force, TCadEntity *ent = 0 );

	bool Contains( const TOGLFloat3 &P, TNPlane pl, double res = RES_COMP );
	bool ContainsByPoints( TOGLPolygon *Pol, TNPlane plane, double res = RES_COMP );
	bool ContainsByIntersect( TOGLPolygon *Pol, TNPlane plane, bool checkclose = false, bool *close = 0 );
	bool TouchArea( TOGLPolygon *PolOut, TOGLPolygon *PolIn, TNPlane plane, bool checkclose = false, bool *close = 0 );
	float DistanceToLine( int start, int end, int p );
	float FarestPoint( int a, int b, int *n );
	void MarkSignificantPoints( int a, int b, float distMin );
	void MarkSignificantPoints( double dist, double maxdist = 0.0 );
	void Filter( double distMin, TOGLPolygon *Pol = 0, TOGLPolygon *Pol2 = 0, double maxdist = 0.0, bool checkboth = true, bool forcefirst = false, bool adjustsize = false, bool adjustdistmintosize = false, bool initmarks = true );
	void FilterMaxError( double errorMax );
	T3DPoint *GetPointsToExport( double filterdist, double filterkeepmindist, bool updatefirst, int &np );

	bool CalcBoundRect( T3DRect &, TNMatrix *mat = 0 );
	bool CalcBoundRectXY( T3DRect & );
	bool CalcBoundRectViewport( TOGLTransf *OGLTransf, TLRect &, int step = 1, TNMatrix *MirrorMat = 0, TInstanceList *list = 0 );
	bool CalcBoundRectInPlane( TLRect &rect, TNPlane plane, int step = 1 );

	bool Offset( double offset );
	void Invert( );
	void ApplyInvertNormals( );
	void ApplyInvertNormals( TNPlane );
	void RecalcNormals( TOGLTransf *, TCadEntity * );
	void ComputeCoordsAndNormals( TOGLTransf *OGLTransf, TCadSurface *surfacepoints, TCadSurface *surfacenormals = 0, bool checkinvertnormals = true );
	void CalculateNormal( TNPlane forceplane = plNone, bool onlyinvalids = false );
	bool CheckAndDeleteDegeneratedTriangles( double prec = RES_COMP, TInteger_List *polsdeleted = 0 );
	bool IsInPlane( T3DPlane &Plane, double prec = RES_GEOM );
	bool IsInPlane( TNPlane Plane );
	bool IsParallelToPlane( TNPlane Plane );

	T3DPoint GetNormal( );
	virtual void ApplyOffsetVarData( TOffsetVarData *offsetvardata );

	bool GetAnglePoint( double ang, T3DPoint vref, bool iniZmin, int &ind, double &tp );

	void ValidateLimits( bool *close, double *limits, double tol_1 );
	void TruncRes10( double tol_1 );
	void ToParamRangeInLimits( bool *close, double *limits, bool uv );
	bool InParamRange( bool *close, double *limits, bool uv = false );
	bool OutParamRange( bool *close, double *limits, double tol_1, bool checkmustclose = true );
	bool DivideByRange( bool *close, double *limitsUV, double tol_1, TOGLPolygonList *Out, bool clear = true );
	bool CloseParamRange( double *limitsUV );
	void GetLimitsUV( double *limits );
	void CompletePoints( double mindist, bool fillUV = true, double maxdist = -1.0 );
	void Extend( double dist, int side = EXTEND_BOTH, double step = -1.0 );
	void ExtendKeepingShape( double dist, int side, double filterdist = 0.0, TNPlane plane = plXY );
	void GetContactPoints( TOGLTransf *OGLTransf, TOGLPolygon *pol, double res, bool checkclose, TCadSurface *surf, bool *close, double *limits, TOGLPolygon *out, bool clear = true );

	void IntersectAt( int from, double d, TOGLPoint &res );
	bool GetNEquidistantPoints( int n, TOGLPolygon *out );
	// isPolyline sirve para si queremos que la ibspline sea una curva (sin corners)
	bool GetNEquidistantPointsSISL( TOGLTransf *OGLTransf, int n, bool isPolyline, bool cornerExtremes, TOGLPolygon *out );

	bool GetNSignificantPoints( int n, TOGLPolygon *out );

	// Normalizacion
	bool IsClockwise( TNPlane Plane = plXY );
	bool IsConcave( TNPlane pl = plNone );
	void ConcaveToConvex( TOGLTransf *OGLTransf, TOGLPolygonList *pList, bool texCoords, bool normalCoords, TNPlane pl = plNone );
	bool IsConvex( );

	// Deprecated: se debe usar T3DData
	//		int NormalizeYZ( TOGLTransf *OGLTransf, TOGLPolygon& out, int nSecs, int *npointsSec, int npointsRef, double angle, double radius, bool renormalize, bool digitPoints = false );
	bool GetRefineList( TOGLPolygon &out, int first, int last, double distance = 2.0 );
	bool GetReduceListByDistance( TOGLPolygon &out, double distMin );
	bool GetRefineListYZ( TOGLTransf *OGLTransf, TOGLPolygon &out, int nadd, bool onlySegments );
	void GetMachiningPointsYZ( TOGLPolygon &out, int pv, double angle, double radio, double tol = RES_GEOM, bool center = false );
	void GetMachiningPoints( TOGLPolygon &out, int pv, double radio, double tol = RES_GEOM, bool center = false );
	bool GetMinMaxValue( int axisMinMax, int &minIndex, double &minValue, int &maxIndex, double &maxValue, int axisLimit = -1, double limit = MAXDOUBLE );
	void SetFirstAt( int index, bool checkclose = false );
	void SetFirstAt( int index, TOGLPoint *p, bool add = true, bool yOrder = true );
	bool GetGeoEquidistPoints( TOGLPolygon &out, int nSecs, int *indexesSec, int *npointsSec );
	double GetCorrectAngle( int pv, double angle, double radius, double tol, bool center );

	void GetGaussMeanList( int range, double weight, TOGLPolygon &out );

	void DrawOGL( TOGLTransf *OGLTransf, bool applytexturecoords );
	bool DrawNonConvexPol( TOGLTransf *oglTransf, TOGLPoint *oglptcolor = 0, bool orCondition = false, bool inv = false, bool chpos1 = false, bool chpos2 = false, TNPlane *plane = 0, bool checkInvert = false, bool mustincrz = false, bool doublestep = false, bool gldraw = true, float backColorFactor = 1.0 );

	virtual void Inflate( TOGLTransf *OGLTransf, double value, bool roundextremes, bool roundcorners, int mark, TOGLPolygon *out );

	virtual bool ParallelAsIBSpline( TOGLTransf *OGLTransf, TParallelData *dist, TParallelTypeData *paralleltypedata, TOGLPolygonList *out );
	virtual bool Parallel( TParallelData *dist, TOGLPolygonList *out, TNPlane pl = plXY, bool checkOppositeSide = true );
	virtual bool CalculateOffset( TParallelData *dist, TOGLPolygonList *out, bool checkOppositeSide = true );
	virtual bool CalculateOffsetInSegments( TParallelData *dist, TOGLPolygonList *out, bool checkOppositeSide, bool &res );
	virtual bool CalculateOffsetInSubSegments( TParallelData *dist, TOGLPolygonList *out, bool checkOppositeSide );
	virtual void CalcCenterPolygon( int method, double distribution, TOGLPolygon *Pol1, TOGLPolygon *Pol2 );

	virtual void PlaneToPlane( TNPlane plsource, TNPlane pldest );
	void ToPlane( T3DPlane plane, T3DVector dir );
	virtual void ProjectToPlane( TNPlane pl );

	virtual bool GetSymAxisPoints( int nTimes, double pct1, double pct2, T3DPoint &p1, T3DPoint &p2 );

	virtual void DeleteRepPts( TOGLPolygon *pol = 0, double res = RES_COMP );
	virtual void DeletePoints( double dist = RES_COMP, TOGLPolygon *relpol = 0 );
	virtual void Open( );
	virtual void Close( bool force = false );
	//		bool operator ==( const TOGLPolygon& other)  { return &other==this; }

	double DistanceSqrToSegment( T3DPoint A, T3DPoint B, T3DPoint &p, T3DPoint &nearest, bool bApplySqrtToDistance = false );

	virtual void ConvertToIBSpline( TOGLTransf *OGLTransf, TCadIBSpline *curve, bool cornerExtremes = false, int mask = CMASK_V );
	virtual void ConvertToPolyline( TOGLTransf *OGLTransf, TCadPolyline *poly, int mask = CMASK_V );

	double GetMaxDistSqrtBetweenConsecutivePoints( );

	void GradeByDirection( double inc, T3DPoint &dir );
	void GradeByLastPoint( T3DPoint newPos );

	int GetIndex( TOGLPoint *pt, int pos, int down, int up, float limitDown, float limitUp, float prec, int compareMask, bool *close = 0, double *limits = 0 );
	bool BreakBySamePoints( TOGLPolygonList *brokenPols );

	int DivideByLoops( TOGLPolygonList *out, TNPlane plane );

	bool CheckArea( double &area, double limitArea = -1 );

  protected:
	TOGLPolygon *CreateTriangle( T3DPointF Point1, T3DPointF Point2, T3DPointF Point3, float Dist );
	TOGLPolygon *CreateTriangle( T3DPointF Point1, T3DPointF Point2, T3DPointF Point3, TOGLPolygon *ptsParallel );
	virtual bool GetOffsetPts( TOGLPolygonList *parallel, GLfloat &Dist, bool RoundCorners, TOGLPolygonList *antiparallel, bool **isCornerPoint );
	virtual bool GetOffsetPtsVar( TOGLPolygonList *parallel, TParallelData *dist, bool test = true );

  public:
	GLenum type;
	bool usenormals, usetextures;
	int MaterialIndex;
	bool TessOrTrim;
	int ToolType, ToolReference;
	UnicodeString ToolLayer;

	bool ForceDevelopSurfIndex; // false no se considera DevelopSurfIndex
	int DevelopSurfIndex;
	bool InactiveDevelop; // Es temporal, no se almacena

	TOGLPoint *Item;
	long dItems, numItems, maxItems;
};

//------------------------------------------------------------------------------

class TGLfloatList;
class TOGLTextureData
{
  public:
	TOGLTextureData( );
	TOGLTextureData( TOGLTextureData *m );
	~TOGLTextureData( );

	void Set( TOGLTextureData *m );
	void SetParameters( TOGLTextureData *m );
	void SetBaseTextureUVList( TGLfloatList *fl );
	void Clear( );
	void ClearParameters( );
	bool IsEqual( TOGLTextureData *data );
	bool EqualCurves( TOGLTextureData *data );
	bool __fastcall operator==( const TOGLTextureData &textureData );

  public:
	int TextureMode;
	double Zoom;	  // Zoom
	double Angle;	  // Angulo giro textura
	TLPoint Origin;	  // Pto. de origen
	bool ForceCenter; // Si true, centra el aplanado en TEXTURE_DEVELOP_SURF en el centro de la textura

	// Auxiliares para calculo de coordenadas de textura finales a partir de las base
	int TempTextureMode;
	bool UseBaseTextures;
	TLPoint LengthUV;
	TLPoint RotationCenter;
	T3DRect Box;
	TGLfloatList *BaseTextureUVList; // vector de coords de texturas base para emulacion de los distintos tipos texturizado en nucleo

	TOGLPolygon PolParamCurve;
	TOGLPolygon PolGeomCurve;
};

//------------------------------------------------------------------------------

class TOGLRenderData;
class TOGLRenderSystem;

class TOGLDisplayData
{
  public:
	// Metodos
	TOGLDisplayData( );
	TOGLDisplayData( GLenum, int, GLfloat, GLfloat, GLfloat, TOGLFloat2, bool isStepRes = true );
	TOGLDisplayData( TOGLDisplayData *dd )
	{
		Set( dd );
	}

	virtual ~TOGLDisplayData( ) { };

	void Set( TOGLDisplayData *dd );

	bool __fastcall operator==( const TOGLDisplayData & );

	// Datos
	GLenum DisplayMode;						  // INES_GLU_FILL, INES_GLU_OUTLINE_PATCH, INES_GLU_SILHOUETTE o INES_GLU_OUTLINE_POLYGON
	int TesselationMode[ N_TESS_ENT_TYPES ];  // Modo de teselado: TESS_NONE, TESS_PATH_LENGTH, TESS_PARAMETRIC_ERROR, TESS_DOMAIN_DISTANCE, TESS_OPTIMUM o TESS_UV
	GLfloat DisplayError[ N_TESS_ENT_TYPES ]; // Calidad de visualizaci??n mm de TESS_PARAMETRIC_ERROR.  //Tolerancia en el teselado
	GLfloat CordalLength[ N_TESS_ENT_TYPES ]; // Longitud de cuerda para el m?do TESS_PATH_LENGTH
	GLfloat Angle[ N_TESS_ENT_TYPES ];		  // Angulo utilizado en el algoritmo de la galleta para TESS_OPTIMUM
	bool IsStepRes[ N_TESS_ENT_TYPES ];		  // booleano para saber si el dato de StepUV es una resolucion o un valor absoluto en el algoritmo de la galleta para TESS_OPTIMUM
	TOGLFloat2 StepUV[ N_TESS_ENT_TYPES ];	  // Pasos a definir cuando se usen los m?dos TESS_DOMAIN_DISTANCE y TESS_UV ( 0:U, 1:V )
	GLfloat QualityFactor;					  // Factor de calidad. Por defecto 1. Se utiliza para obtener render de mas baja calidad, sobre todo para exportaciones
};

//------------------------------------------------------------------------------

class TCadShape;
class TCadTensorSurface;
class T3DPolygonList;
class T3DRectList;
class TOGLPointerPolygonList;

typedef struct _NodeToNormals {
	int indpol, indvtx, indtrg, indc, indgrp;
	bool averaged;
	struct _NodeToNormals *next;
} NodeToNormals;

class TOGLPolygonList
{
	friend class TImpExp_XML;

  public:
	TOGLPolygonList( long di = DEFAULT_DITEMS_LIST );
	virtual ~TOGLPolygonList( );

	void Clear( bool adjustsize = false );
	void ClearUV( );
	void ClearT( );
	void CleanAll( );

	void Set( TOGLPolygonList *List );
	void Set( T3DPolygonList *List );
	void DeleteItem( int ind );
	void DeleteAllItems( int excludeind );
	void SetItems( TOGLPolygonList *List );
	void SetUV( TOGLPolygonList *List );
	void SetUVFromV( bool clearv = true );
	void SetUVFromT( );
	void SetVFromUV( bool clearuv = true );
	void SetT( TOGLPolygonList *List );
	void SetTFromV( );
	void TransferAll( TOGLPolygonList *origin );

	TOGLPolygon **GetItems( )
	{
		return Item;
	}
	long GetMaxItems( )
	{
		return maxItems;
	}
	long GetDItems( )
	{
		return dItems;
	}

	void GrowItems( long d = 0 );
	void AdjustSize( long dI = 0 );
	void AddAtFirst( TOGLPolygon *p, bool forcebtype = false, bool forcetriangles = false );
	void Add( TOGLPolygon *p, bool forcebtype = false, bool forcetriangles = false, bool adjustmaxsize = false );
	void AddPtr( TOGLPolygon *Pol );
	void Append( TOGLPolygonList *list );

	void SetOGLDisplayData( int, GLenum, int, GLfloat, GLfloat, GLfloat, TOGLFloat2, bool = true, GLfloat *qualityfactor = 0 );
	void GetOGLDisplayData( int, GLenum &, int &, GLfloat &, GLfloat &, GLfloat &, TOGLFloat2 &, bool &, GLfloat *qualityfactor = 0 );
	void SetOGLDisplayData( TOGLDisplayData * );
	TOGLDisplayData *GetOGLDisplayData( )
	{
		return &OGLDisplayData;
	}

	void SetItem( long a, TOGLPolygon *Pol ); // Se exige igual tama??el pol?no a asignar
	TOGLPolygon *GetItem( long a );
	TOGLPolygon *GetFirstItem( );
	TOGLPolygon *GetLastItem( );
	TOGLPolygon *GetPrelastItem( );
	bool GetSubItem( long i, long lim1, long lim2, TOGLPolygon *Pol );
	bool GetSubItem( double pct1, double pct2, bool checkclose, bool *close, double *limits, TOGLPolygon *Pol );
	bool GetSubItem( int indp1, int ind1, double pct1, int indp2, int ind2, double pct2, bool checkclose, bool *close, double *limits, TOGLPolygon *Pol );
	bool GetSubItems( double pct1, double pct2, bool checkclose, bool *close, double *limits, TOGLPolygonList *List );
	bool GetSubItems( int indp1, int ind1, double pct1, int indp2, int ind2, double pct2, bool checkclose, bool *close, double *limits, TOGLPolygonList *List );

	long Count( )
	{
		return numItems;
	}
	int GetLongestIndex( );
	int GetMaxAreaIndex( );

	long ReadPolNumVertexs( int a = -1 );
	bool IsNormalized( );

	bool IsCloseExt( bool checkclose = false, bool *close = 0, double *limits = 0, bool uv = false );
	T3DPoint GravityCenter( );
	T3DPoint GravityCenter( double inc );
	double Perimeter( );
	double GetRelatedDistance( TOGLTransf *OGLTransf, TCadShape *shape, double dist );
	double GetPctFromPolPct( int indp, double polpct, double per = 0.0 );
	double GetPolPctFromPct( double pct, int &indp, double &polper, double per = 0.0, double auxpct = -1.0 );

	// Estas 5 funciones estan bien hechas para tratar correctamente las operaciones sobre listas con varios poligonos
	double *GetPcts( double per = -1.0 );
	double GetPct( TOGLFloat3 *v, double per = 0.0 );
	double GetPctFromRaster( TOGLTransf *OGLTransf, TPoint point, double per = 0.0, int wndheight = -1, TOGLFloat3 *outvtx = 0 );
	bool GetPointAndNormalFromPct( double pct, double p, T3DPoint &pt, T3DPoint &n, double dist = 1.0, T3DPoint axis = T3DPoint( 0.0, 0.0, 1.0 ), bool checkclose = false, bool *close = 0, double *limits = 0, int extendside = EXTEND_BOTH, double auxpct = -1.0 );
	bool GetVertexFromPct( double pct, double per, TOGLFloat3 *v, double auxpct = -1.0, int *indp = 0 );
	void GetPerimeterIndexPct( double dist, int &indp, int &index, double &pct );

	bool GetVertex( int, int, TOGLFloat3 & );
	bool GetVertexUV( int, int, TOGLFloat2 & );
	double GetNearestVertex( TOGLFloat3 *, bool checkparam, bool *close, double *limits, int &, int &, TOGLFloat3 & );
	bool GetNearestPoint( TOGLFloat3 *v, T3DPoint &pt );
	double GetNearestVertexX( TOGLFloat3 *, int &, int &, TOGLFloat3 & );
	bool GetLines( TOGLPolygonList *out );
	bool GetLineStrips( TOGLPolygonList *out );
	bool AreTriangles( );
	bool AreQuads( );
	bool ArePolygons( );
	bool GetTriangles( vector<TOGLPoint> *v, vector<GLint> *vi, int comparemask = CMASK_ALL, bool checkdegeneratedtriangles = true, double prec = 0.0001, bool *close = 0, double *limits = 0 );
	bool GetTrianglesCoords( vector<TOGLPoint> *v, vector<GLint> *vi, int comparemask = CMASK_ALL, bool checkdegeneratedtriangles = true, double prec = 0.0001, bool *close = 0, double *limits = 0, TOGLPolygonList *secondlist = 0, vector<TOGLPoint> *secondv = 0, int checksecondtype = 0 );
	bool GetPolygons( vector<TOGLPoint> *v, vector<GLint> *vi, vector<int> *vn, int comparemask = CMASK_ALL, bool checkdegeneratedpolygons = true, double prec = 0.0001, bool *close = 0, double *limits = 0 );
	bool GetPolygonsCoords( vector<TOGLPoint> *v, vector<GLint> *vi, vector<int> *vn, int comparemask = CMASK_ALL, bool checkdegeneratedpolygons = true, double prec = 0.0001, bool *close = 0, double *limits = 0, TOGLPolygonList *secondlist = 0, vector<TOGLPoint> *secondv = 0, int checksecondtype = 0 );
	void GetTree( vector<TOGLPoint> *v, vector<GLint> *vi, int dimension = 16, int comparemask = CMASK_ALL, bool checkdegeneratedtriangles = true );
	TOGLPoint *GetTreeVertexs( int &npts );
	void SetTreeNewDataPoints( T3DPoint *new_points );
	vector<GLint> *GetTree_vi( )
	{
		return vi_polygonList;
	}
	bool IntersectTriangles( T3DPlane &Plane, TOGLPolygonList *OGLList, TOGLFloat3 *startPointRef = NULL );
	void EqualizeVertexs( int dimension = 16, int comparemask = CMASK_ALL, double prec = RES_COMP );
	bool SectionsToTriangles( TOGLPolygonList *out, int step = 1 );
	bool CloseExtremes( TOGLTransf *OGLTransf, TOGLPolygonList &out, int method = MT_CLOSE_CIRCLE );
	TCadTensorSurface *SectionsToTensor( int closeextremes = CLOSE_NONE, int ustep = 1, int vstep = 1 );
	// Deprecated: se debe usar T3DData
	// int Normalize( TOGLTransf *OGLTransf, TOGLPolygonList &out, int pv, int npointsRef, double angle, double radius, bool force, int uini, int ufin );

	bool FitToRect( TOGLTransf *, T3DPoint, T3DPoint, TCadEntity * = 0, bool force = false );
	void Move( T3DPoint );
	void MoveX( double incr );
	void MoveY( double incr );
	void MoveFromTo( T3DPoint org, T3DPoint dst );
	void Scale( T3DPoint );
	void ApplyMatrix( TNMatrix *matrix, bool checkusenormals = true );
	void ApplyMatrixXY( TNMatrix *matrix );
	void RotateXY( T3DPoint center, double Angle, bool rad = false, double *sinangle = 0, double *cosangle = 0 );
	void HMirror( TOGLFloat3 *m, TOGLFloat3 *M, TNPlane plane, bool inverted );
	void VMirror( TOGLFloat3 *m, TOGLFloat3 *M, TNPlane plane, bool inverted );
	void MirrorX0( bool invert = true );
	void MirrorY0( bool invert = true );
	void SymAxis( T3DPoint p1, T3DPoint p2 );
	void SymPlane( T3DPlane plane );
	void RevertSecondDevelopSurfIndex( TOGLTransf *OGLTransf, bool force, TCadEntity *ent = 0 );

	void Difference( T3DPoint pt, T3DVector normal, TOGLPolygonList *OGLListOut1, TOGLPolygonList *OGLListOut2 = 0 );
	void ReduceTesselation( int ownclose, bool checkparam = false, bool *close = 0, double *limits = 0, double resparam = RES_COMP );
	void Filter( double dist, TOGLPolygonList *List = 0, TOGLPolygonList *List2 = 0, double maxdist = 0.0, bool checkboth = true, bool forcefirst = false, bool adjustsize = false, bool adjustdistmintosize = false );

	bool CalcBoundRect( T3DRect &, TNMatrix *mat = 0 );
	bool CalcBoundRectXY( T3DRect & );
	bool CalcBoundRectViewport( TOGLTransf *OGLTransf, TLRect &, int step = 1, TNMatrix *MirrorMat = 0, TInstanceList *list = 0 );
	bool CalcBoundRectInPlane( TLRect &rect, TNPlane plane, int step = 1 );

	void ValidateLimits( bool *close, double *limits, double tol_1 );
	void TruncRes10( double tol_1 );
	void ToParamRangeInLimits( bool *close, double *limits, bool uv );
	bool InParamRange( bool *close, double *limits, bool uv = false );
	bool OutParamRange( bool *close, double *limits, double tol_1, bool checkmustclose = true );
	void DivideByRange( bool *close, double *limitsUV, double tol_1 );
	void GetLimitsUV( double *limits );
	void CompletePoints( double mindist, bool fillUV = true, double maxdist = -1.0 );
	void DeleteRepPts( TOGLPolygonList *list = 0, double res = RES_COMP );
	void Extend( double dist, int side = EXTEND_BOTH, bool inside = false, double step = -1.0 );
	void ExtendKeepingShape( double dist, int side, double filterdist = 0.0, TNPlane plane = plXY, bool inside = false );

	void GetContactPoints( TOGLTransf *OGLTransf, TOGLPolygonList *list, double res, bool checkclose, TCadSurface *surf, bool *close, double *limits, TOGLPolygon *out, bool clear = true );

	bool IsSamePolType( GLenum &type, int &nt );
	bool Offset( double offset );
	void ApplyInvertPolygons( bool invertlist = false );
	void InvertList( );
	void SetFirstAt( TOGLPoint pt, bool checkclose = false );
	void ApplyInvertNormals( );
	void RecalcNormals( TOGLTransf *OGLTransf, TCadEntity *paramsurf );
	void ComputeCoordsAndNormals( TOGLTransf *OGLTransf, TCadSurface *surfacepoints, TCadSurface *surfacenormals = 0, bool checkinvertnormals = true );
	void CalculateNormal( TNPlane forceplane = plNone, bool onlyinvalids = false );
	void DeleteDegeneratedTriangles( double prec = RES_COMP, TInteger_ListList *polsdeleted = 0 );
	void CheckInvertedPolygons( TOGLTransf *OGLTransf );

	void Intersect( TOGLPolygonList *OGLList, TOGLPolygon *Out, TOGLPolygon *Out2 = 0, TNPlane plane = plXY, double res = 0.0, bool checkclose = false, bool *close = 0, bool clear = true );
	bool GetIntersectRange( TOGLPolygon *Pol, double &pct1, double &pct2, TNDoublesList *segments = 0, bool excludeholes = false );

	bool GetFirstIntersectPoint( T3DVector v, T3DPoint *p, bool force = false );

	bool IsInPlane( TNPlane Plane );
	bool IsParallelToPlane( TNPlane Plane );

	virtual void ApplyOffsetVarData( TOffsetVarData *offsetvardata );
	T3DPoint GetNormal( );

	virtual void PlaneToPlane( TNPlane plsource, TNPlane pldest );
	void ToPlane( T3DPlane plane, T3DVector dir );
	virtual void ProjectToPlane( TNPlane pl );

	float *GetBufferData( TOGLTransf *OGLTransf, GLenum &type, int &n, bool &usecolors, TOGLRenderData *_OGLRdData );
	bool GetBufferData( TOGLTransf *OGLTransf, GLenum &type, int &nvertices, float **vertices, int &nindices, unsigned int **indices, bool &usecolors, TOGLRenderData *_OGLRdData );
	TOGLPoint *GetOGLPoints( int &np );
	T3DPoint *GetPoints( int &np );
	T3DPoint *GetPointsUV( int &np );
	T3DPoint *GetNormals( int &np );
	T3DPoint *GetTextureCoords( int &np );
	T3DPoint *GetInvertedPts( int &np );
	bool SameVertexs( TOGLPolygonList *list );
	bool IsHomogeneous( TOGLPolygonList *list );

	void ApplyOGLMaterialExt( TOGLRenderData *_OGLRdData, bool usecolors, int matindex );

	void DrawOGL( TOGLTransf *OGLTransf, TOGLRenderData *_OwnOGLRdData, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem, bool applytexturecoords, bool drawOGLExtMode = false );
	void DrawOGL_Basic( TOGLTransf *OGLTransf, TOGLRenderData *_OwnOGLRdData, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem, bool applytexturecoords, bool drawOGLExtMode, bool startCompilation = true, bool endCompilation = true, float backColorFactor = 1.0 );
	void DrawOGL_Shaders_Basic( TOGLTransf *OGLTransf, TOGLRenderData *_OwnOGLRdData, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem, bool applytexturecoords, bool drawOGLExtMode );
	void DrawOGL_Shaders_PBR( TOGLTransf *OGLTransf, TOGLRenderData *_OwnOGLRdData, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem, bool applytexturecoords, bool drawOGLExtMode );
	void DrawOGL_Shaders_PBR_Shadows( TOGLTransf *OGLTransf, TOGLRenderData *_OwnOGLRdData, TOGLRenderData *_OGLRdData, TOGLRenderSystem *_OGLRdSystem, bool applytexturecoords, bool drawOGLExtMode );

	void ClearID( );
	void SetID( int );
	void SetIsCompiledOGL( bool value );
	void Download_glList( );

	void GetBOS( );
	void Download_BOS( bool del = false );
	void SetAreValidBOS( bool value );

	void Download( );

	int GetSimilarPol( TOGLPolygon *Pol, int np, bool excludefirst = false );
	void OrderByBounds( TNPlane plane, bool excludefirst = false );
	//		void OrderByContains( TNPlane plane, int **_numContains = 0 );
	//		int GetDeeperIndexContainsPoint( TOGLFloat3 *vtx, TNPlane plane, int *_nContains );
	//		void GetPolIndexesContainsByPol( int index, TNPlane plane, TInteger_List *indexes );
	void GetOGLBoundaries( int Type, bool clockWise, TOGLPolygonList *OGLListTess, bool checkclose = false, bool *close = 0, double *limits = 0 );
	void UnifyNormals( double maxdegangle = -1.0, bool fineAdjust = false, vector<TOGLPoint> *_v = 0, vector<GLint> *_vi = 0, int comparemask = CMASK_V, bool onlyinvalid = false );
	void ConvertQuadStripsToQuads( );
	void ConvertToTriangles( TOGLPolygonList *out = 0, int type = SINGLE_POLYGON, int comparemask = CMASK_ALL, TOGLPolygonList *secondlist = 0, TOGLPolygonList *secondlistout = 0, int checksecondtype = 0, bool force = false );
	void ConvertToPolygons( TOGLPolygonList *out = 0, int type = SINGLE_POLYGON, int comparemask = CMASK_ALL, TOGLPolygonList *secondlist = 0, TOGLPolygonList *secondlistout = 0 );
	void DivideTriangles( TOGLPolygonList *out, double maxlength2 );

	void GetMachiningPoints( TOGLPolygon &out, int pv, double radio, double tol = RES_GEOM );
	void GetWrap( TOGLTransf *OGLTransf, double startdist, double enddist, double filterdist, bool fitdistances, TOGLPolygon *out );
	void GetConvexHull( TOGLTransf *OGLTransf, double enddist, TOGLPolygon *out, bool complete = true );

	// Nueva libreria SMLib
	bool Decimate( TOGLPolygonList *OGLListOut, bool repair = true, double dPercentOfReduction = 0.0, double dMaximumError = 0.0, bool bUseEdgeLengthAsError = false, double dMinFeatureAngle = 30.0, double dInteriorEdgeWeight = 1.0, double dBoundaryEdgeWeight = 1.0, bool converttotriangles = true );
	bool DecimateSolid( TOGLPolygonList *OGLListOut, double dPercentOfReduction = 0.0, double dMaximumError = 0.0, bool bUseEdgeLengthAsError = false, double dMinFeatureAngle = 30.0, double dInteriorEdgeWeight = 1.0, double dBoundaryEdgeWeight = 1.0 );

	void JoinPolygons( TOGLPolygon *out, double tol = 2, double maxtol = -1 );
	void JoinPolygons( TOGLPolygonList *out, double tol = 2, double maxtol = -1 );
	bool CheckIntersectXY( TOGLPolygonList *PolList, T3DRectList *r3dList = 0, T3DRectList *r3dPolList = 0 );
	bool CheckIntersectXY( TOGLPointerPolygonList *PolListPtr, T3DRectList *r3dList = 0, T3DRectList *r3dPolList = 0 );

	void SetTexCoordsFromOtherTesselation( TOGLTransf *OGLTransf, TCadEntity *refEnt, IwTree *tree, TOGLPolygonList *texCoordsOrig, TOGLPolygonList *polListDest, int startIndex, int endIndex, int textureIndex, bool compNormals );

	void RemoveEmptyPols( double area );
	bool CheckArea( double &area, double limitArea = -1 );

	bool RepairTrianglesUV( TOGLTransf *OGLTransf, TCadSurface *surf );

	void Trim( TOGLPolygon *BorderPol, TOGLPolygonList *Out = 0 );

  protected:
	TOGLPolygon **Item;
	long dItems, numItems, maxItems;
	vector<TOGLPoint> *vt_polygonList;
	vector<GLint> *vi_polygonList;

	GLsizei SizeVBO, SizeEBO;
	GLenum TypeVBO;
	bool LastUseColorsBOS, LastUseColorsBasic, LastDrawOGLExtMode;

  public:
	int ID;
	bool IsCompiledOGL;
	TOGLMaterialExtList CompiledMaterials;
	HDC hOGLDC;	  // Device Context del dispositivo de dibujado
	HGLRC hOGLRC; // Render Context en donde se guardaran las listas

	unsigned int VBO, EBO;
	bool AreValidBOS;
	HDC hOGLDCBOS;	 // Device Context del dispositivo de dibujado
	HGLRC hOGLRCBOS; // Render Context en donde se guardaran las listas

	TOGLDisplayData OGLDisplayData;
};

//------------------------------------------------------------------------------

class TOGLPolygonListList
{
  public:
	TOGLPolygonListList( );
	~TOGLPolygonListList( );

	void Clear( );
	int Count( );
	void Grow( int d );

	void Set( TOGLPolygonListList * );
	void Init( int nitems, int curitem );

	void AddItem( TOGLPolygonList *s );
	void SetItem( int ind, TOGLPolygonList *s );
	void InsertItem( int ind, TOGLPolygonList *s );
	void DelItem( int ind );
	TOGLPolygonList *GetItem( int ind );
	void ReplaceItems( int ind1, int ind2 );

	virtual int GetCurrentIndex( );
	virtual void SetCurrentIndex( int );
	virtual TOGLPolygonList *GetCurrentItem( );

	bool CalcBoundRect( T3DRect &, TNMatrix *mat = 0 );

  public:
	int numItems, maxItems, curItem;
	TOGLPolygonList *Item;
};

//------------------------------------------------------------------------------

class TOGLPointerPolygonList
{
  public:
	TOGLPointerPolygonList( );
	virtual ~TOGLPointerPolygonList( );

	virtual void Clear( int items = 10 );

	virtual void AddItem( TOGLPolygon *td );
	virtual void SetItem( int ind, TOGLPolygon *td );
	virtual void DelItem( TOGLPolygon *td = 0 ); // 0 borra
	virtual void DeleteItem( int index );		 // para que no confunda con la anterior
	virtual TOGLPolygon *GetItem( int ind );

	virtual int Count( );
	virtual void Grow( int d );

  protected:
	int numItems, maxItems;
	TOGLPolygon **Item;
};

//------------------------------------------------------------------------------

class TApplyOGLRenderDataParams
{
  public:
	TApplyOGLRenderDataParams( )
	{
	}

	virtual void Get( );
	virtual void Set( bool bLineWidth = true );
	void SetData( TApplyOGLRenderDataParams * );

  protected:
	GLboolean bColorMaterial;
	GLboolean bLighting;
	GLboolean bLineStipple;
	GLboolean bTexture2D;
	GLboolean bTextureGenS;
	GLboolean bTextureGenT;

	GLenum iColorMaterialParameter;
	GLenum iColorMaterialFace;

	GLint iShadeModel;
	GLint iTextureGenModeS;
	GLint iTextureGenModeT;

	GLfloat fLineWidth;
};

//------------------------------------------------------------------------------

#define DSAM_NORMAL		   0
#define DSAM_ONLYEXTREMES  1
#define DSAM_STEP_EXTREMES 2
#define DSAM_STEP_LINE	   3

#define DMIS_NONE		   0
#define DMIS_NORMAL		   1
#define DMIS_INVERT		   2

class TOGLRC;

class TOGLRenderSystem
{
  public:
	TOGLRenderSystem( );
	~TOGLRenderSystem( );

	void Set( TOGLRenderSystem * );

	TOGLMaterial *GetMaterial( int i )
	{
		return ( i >= 0 && i < SYSTEM_MATERIALS ) ? &( Material[ i ] ) : 0;
	}
	void SetSystemMats( TOGLMaterial * );

  public:
	bool IsSelectMode; // Indica si estamos en modo de seleccion modo de dibujado
	bool IsShadowMode; // Indica si estamos en modo de dibujado de sombras
	bool IsMarkersMode;
	bool IsPointRelationsMode; // Indica si estamos en modo de edicion relaciones de punto

	bool DrawAsUnselect;
	bool InactiveDevelopVisible;
	bool UseDrawings;
	bool UseReferences;

	int DrawPointMarkers;
	int PointMarkerIndex;
	int DrawLineMarkers;
	int DrawMarkersMode;
	TInteger_List *DrawMarkerIndexes; // Se refiere a la vble Index de los marcadores de tipo punto y linea
	int DrawMarkerIndexSense;
	float BiggerCadPoints;

	bool HideFixPoints;
	bool DrawPointRelations;
	int PointRelationIndex;
	bool DrawingDeps;
	bool DrawOnlyMarkers;
	bool DrawCenterArrow;
	bool InvertCenterArrow;
	bool DrawSEAreas;
	bool DrawRenderCutPlanes;

	int RecalcEntities; // M?ara indicando que entidades recalcular

	int SelectedFillEntityMode; // Modo dibujado entidades seleccionadas
	int DrawAsUnselectedMode;	// Modo dibujado entidades no seleccionadas
	bool DrawNormalsMode;
	bool DrawBorderRect;
	bool DrawFullCamera;
	bool UseCompilations; // Dibujar utilizando las listas de compilacion
	bool CompileShapes;	  // Permite compilar o no las entidades tipo shape
	int ForceNameID;	  // Fuerza a llamar a glLoadName con este ID en lugar del de la entidad
	bool ForceCullFace;
	bool EnablePolygonOffset;

	float NodeSize;
	float RotPtSize;
	float RefRotPtSize;
	float LineWidth;
	float LineWidthFactor;
	float SilhouetteWidth;

	bool DrawRto3DObjectOptimized; // Dibujar los poligonos para seleccion de objetos 3D unificados
	int DrawSelectedAxisMode;	   // DSAM_NORMAL, DSAM_ONLYEXTREMES, DSAM_STEP1, DSAM_STEP2
	bool DrawMeshFacesMode;
	int ForceDrawMeshFacesFill; //-1, 0=force FILL, 1= force SILHOUETTE

	bool DrawShadows, DrawWithoutTranslucent, DrawMaskTranslucent;

	bool Stipple[ SYSTEM_STIPPLES ];
	int StippleFactor[ SYSTEM_STIPPLES ];
	GLushort StipplePattern[ SYSTEM_STIPPLES ];

	TOGLMaterial Material[ SYSTEM_MATERIALS ];
	TLight Lights[ W3DOGL_MAX_LIGHTS ];

	bool UseApplyOGLRdDataParams;
	TApplyOGLRenderDataParams ApplyOGLRdDataParams;

	TOGLRC *OGLRC;

	bool DrawNonConvex;		 // Permite el pintado de caras no convexas
	bool DrawFrontBackColor; // Permite el pintado de caras interior y exterior de diferente color

	bool ClearOGLFillListOffset;
};

//------------------------------------------------------------------------------

class TOGLRenderDataMaterial
{
  public:
	TOGLRenderDataMaterial( );

	void Set( TOGLRenderDataMaterial * );
	void SetBasic( TOGLRenderDataMaterial * );

	bool GetStipple( int index = -1 );
	int GetStippleFactor( int index = -1 );
	GLushort GetStipplePattern( int index = -1 );
	void SetStipple( bool value, int index = -1 );
	void SetStippleFactor( int value, int index = -1 );
	void SetStipplePattern( GLushort value, int index = -1 );

	TOGLMaterial *GetMaterial( int side, int texmat = -1, int index = -1 );
	void SetMaterial( TOGLMaterial *m, int side, int texmat = -1, int index = -1 );
	void CheckMaterials( int index = -1 );
	bool IsSingleMaterialUsed( );

	bool __fastcall operator==( const TOGLRenderDataMaterial &oglrdmat );

  public:
	bool ActiveTextureMat;
	TOGLMaterialExtList MtNoTextureList;
	TOGLMaterial MtTexture; // Material con textura
};

//------------------------------------------------------------------------------

class TOGLRenderDataMaterialList
{
  public:
	TOGLRenderDataMaterialList( );
	~TOGLRenderDataMaterialList( );

	void Clear( );
	int Count( );
	void Grow( int d );

	void Set( TOGLRenderDataMaterialList * );
	void SetBasic( TOGLRenderDataMaterialList *, bool onlycuritem = false );

	void AddItem( TOGLRenderDataMaterial *s );
	void SetItem( int ind, TOGLRenderDataMaterial *s );
	void InsertItem( int ind, TOGLRenderDataMaterial *s );
	void DelItem( int ind );
	TOGLRenderDataMaterial *GetItem( int ind );
	void ReplaceItems( int ind1, int ind2 );

	virtual int GetCurrentIndex( );
	virtual void SetCurrentIndex( int );
	virtual TOGLRenderDataMaterial *GetCurrentItem( );

	bool __fastcall operator==( const TOGLRenderDataMaterialList &oglrdmatlist );

  public:
	int numItems, maxItems, curItem;
	TOGLRenderDataMaterial *Item;
};

//------------------------------------------------------------------------------

class TOGLRenderData
{
  public:
	TOGLRenderData( );
	~TOGLRenderData( );

	void Set( TOGLRenderData *, bool copyDisplayData = true );
	void SetBasic( TOGLRenderData *, bool copyDisplayData = true, bool onlycuritem = false );

	virtual void SetOGLDisplayData( int, GLenum, int, GLfloat, GLfloat, GLfloat, TOGLFloat2, bool = true, GLfloat *qualityfactor = 0 );
	virtual void SetOGLDisplayData( TOGLDisplayData * );
	virtual TOGLDisplayData *GetOGLDisplayData( )
	{
		return &OGLDisplayData;
	}

	bool GetStipple( int index = -1 );
	int GetStippleFactor( int index = -1 );
	GLushort GetStipplePattern( int index = -1 );
	void SetStipple( bool value, int index = -1 );
	void SetStippleFactor( int value, int index = -1 );
	void SetStipplePattern( GLushort value, int index = -1 );

	TOGLMaterial *GetMaterial( int side, int texmat = -1, int index = -1, int matlistindex = -1 );
	void SetMaterial( TOGLMaterial *m, int side, int texmat = -1, int index = -1, int matlistindex = -1 );
	void CheckMaterials( int index = -1 );
	bool IsSingleMaterialUsed( );
	void ClearUnusedMaterial( int matlistindex = -1 );

	void SetActiveTextureMat( bool value, int matlistindex = -1 );
	bool GetActiveTextureMat( int matlistindex = -1 );
	TOGLMaterialExtList *GetMtNoTextureList( );
	TOGLMaterial *GetMtTexture( );

	void SetColors( TOGLPolygonList *list );
	void ClearColors( );
	void ClearTextureUV( );
	void ClearTextureUVListID( );

	void CheckTextureUVList( );
	void CheckTextureUVCoords( );
	void ClearTextureUVList( );
	void ClearTextureUVCoords( );

	int CountColors( );
	int CountTextureUVList( );
	int CountTextureUVCoords( );
	void SetTextureUVList( TOGLTextureList *list );
	void SetTextureUVCoords( TOGLPolygonList *list );

	bool __fastcall operator==( const TOGLRenderData &ogl );

	void ReadMaterials( UnicodeString *currentpath, UnicodeString *matnameOrig, UnicodeString *librarynameOrig, UnicodeString *dstpath = 0, bool checkboth = false, bool cancopymaxwell = true );
	void SaveMaterialsMTR( UnicodeString library, UnicodeString *pathroot = 0 );

	void CopyMaterialsToPath( UnicodeString *newpath, bool force = true, bool checktexture = true, bool cancopymaxwell = true );
	void UpdatePathOwnMaterials( UnicodeString *newpath );
	void CheckPathOwnMaterials( UnicodeString *newpath );
	void ClearMaterialsFromPath( );

	void GetTextureUVCoordsNormals( TOGLPolygon *oglpol );
	void SetTextureUVCoordsNormals( TOGLPolygon *oglpol );

	void SynchronizePBR( int matlistindex = -1 );

	void UpdateEditionDate( );

  public:
	TOGLDisplayData OGLDisplayData;

	bool Smooth;			   // Utilizado cuando DisplayMode es INES_GLU_FILL
	double Smooth_MaxDegAngle; // Angulo max a aplicar en el suavizado de normales para mallas poligonales
	bool CullFace;			   // Utilizado cuando DisplayMode es INES_GLU_FILL

	TOGLRenderDataMaterialList MaterialList;

	bool ActiveUseOfSecondaryMat;
	TOGLMaterialExt *MtSecondary; // Material secundario

	bool ActiveTextureUV;
	TOGLTextureList *TextureUVList; // Texture propia
	TOGLPolygonList *TextureUVCoords;

	bool TextureTransparent; // Fuerza a transparente el material de textura, normal o propia, en el pad

	bool ActiveColors;
	TOGLPolygonList *Colors; // Color de cada vertice

	bool DependentAsBase;
	int DefLineWidth;
};

//------------------------------------------------------------------------------

class TOGLRenderDataList
{
  public:
	TOGLRenderDataList( );
	~TOGLRenderDataList( );

	void Clear( );
	int Count( );
	void Grow( int d );
	void AdjustSize( int c );

	void AddItem( TOGLRenderData *data );
	void SetItem( int ind, TOGLRenderData *data );
	void DelItem( int ind );
	TOGLRenderData *GetItem( int ind );

  public:
	int numItems, maxItems;
	TOGLRenderData **Item;
};

//------------------------------------------------------------------------------

class TOGLErrorData
{
  public:
	TOGLErrorData( );
	virtual ~TOGLErrorData( )
	{
	}

	virtual void Set( TOGLErrorData *E );
	virtual void Set( int, double, TColor, TColor, TColor );
	virtual void Clear( );

  public:
	int NumColors;
	double Factor;
	TColor MinError, CenterError, MaxError;
	TOGLPolygon Colors, Limits;
};

//------------------------------------------------------------------------------

class TOGLCallbackData
{
  public:
	TOGLCallbackData( );

	void Set( TOGLCallbackData *data );

  public:
	int Dim;
	double Res;
	TOGLPoint *Point;
	TOGLPointExt *AddedPoints;
	TOGLPolygon *Pol;
	TOGLPolygonList *List;

	bool Error;
	int MaxPols;
};

#endif

