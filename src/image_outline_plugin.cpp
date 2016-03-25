/**\file image_outline_plugin.cpp
 * \brief Gazebo CameraPlugin that creates image outlines
 *
 * @version 1.0
 * @author Carlos Miguel Correia da Costa
 */
 

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  <includes>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
#include <image_outline_plugin/image_outline_plugin.h>
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  </includes>  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


namespace gazebo {
// =============================================================================  <public-section>  ============================================================================
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   <functions>   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
ImageOutlinePlugin::ImageOutlinePlugin() : image_count_(0) {
	vector_image_publisher_.setupZMQ();
}


void ImageOutlinePlugin::Load(sensors::SensorPtr _parent, sdf::ElementPtr _sdf) {
	CameraPlugin::Load(_parent, _sdf);
}


void ImageOutlinePlugin::OnNewFrame(const unsigned char *_image, unsigned int _width, unsigned int _height, unsigned int _depth, const std::string &_format) {
	std::cout << "Received image number " << image_count_++ << " from sensor [" << this->parentSensor->GetCamera()->GetName().c_str()
						<< "] with format " << _format << " [" << _width << " x " << _height << " @ " << _depth << "]" << std::endl;
//	image_tracer_.processImage(_image, _width, _height, _depth, _format);

	std::stringstream ss;
	ss << "Image number " << image_count_;
	vector_image_publisher_.sendMessage(ss.str());
}
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   </functions>  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// =============================================================================  </public-section>  ===========================================================================
}
