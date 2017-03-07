/* -*-c++-*- IFC++ www.ifcquery.com
*
MIT License

Copyright (c) 2017 Fabian Gerold

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <sstream>
#include <limits>

#include "ifcpp/model/IfcPPException.h"
#include "ifcpp/model/IfcPPAttributeObject.h"
#include "ifcpp/model/IfcPPGuid.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IfcPPEntityEnums.h"
#include "include/IfcCartesianPointList2D.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

// ENTITY IfcCartesianPointList2D 
IfcCartesianPointList2D::IfcCartesianPointList2D() { m_entity_enum = IFCCARTESIANPOINTLIST2D; }
IfcCartesianPointList2D::IfcCartesianPointList2D( int id ) { m_id = id; m_entity_enum = IFCCARTESIANPOINTLIST2D; }
IfcCartesianPointList2D::~IfcCartesianPointList2D() {}
shared_ptr<IfcPPObject> IfcCartesianPointList2D::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcCartesianPointList2D> copy_self( new IfcCartesianPointList2D() );
	copy_self->m_CoordList.resize( m_CoordList.size() );
	for( size_t ii=0; ii<m_CoordList.size(); ++ii )
	{
		std::vector<shared_ptr<IfcLengthMeasure> >& vec_ii = m_CoordList[ii];
		std::vector<shared_ptr<IfcLengthMeasure> >& vec_ii_target = copy_self->m_CoordList[ii];
		for( size_t jj=0; jj<vec_ii.size(); ++jj )
		{
			shared_ptr<IfcLengthMeasure>& item_jj = vec_ii[jj];
			if( item_jj )
			{
				vec_ii_target.push_back( dynamic_pointer_cast<IfcLengthMeasure>( item_jj->getDeepCopy(options) ) );
			}
		}
	}
	return copy_self;
}
void IfcCartesianPointList2D::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "= IFCCARTESIANPOINTLIST2D" << "(";
	writeNumericTypeList2D( stream, m_CoordList );
	stream << ");";
}
void IfcCartesianPointList2D::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcCartesianPointList2D::readStepArguments( const std::vector<std::wstring>& args, const map_t<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args != 1 ){ std::stringstream err; err << "Wrong parameter count for entity IfcCartesianPointList2D, expecting 1, having " << num_args << ". Entity ID: " << m_id << std::endl; throw IfcPPException( err.str().c_str() ); }
	readTypeOfRealList2D( args[0], m_CoordList );
}
void IfcCartesianPointList2D::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	IfcCartesianPointList::getAttributes( vec_attributes );
}
void IfcCartesianPointList2D::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes_inverse )
{
	IfcCartesianPointList::getAttributesInverse( vec_attributes_inverse );
}
void IfcCartesianPointList2D::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcCartesianPointList::setInverseCounterparts( ptr_self_entity );
}
void IfcCartesianPointList2D::unlinkFromInverseCounterparts()
{
	IfcCartesianPointList::unlinkFromInverseCounterparts();
}