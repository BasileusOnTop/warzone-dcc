# Copyright (c) 2013 Daniele Bartolini, Michele Rossi
# Copyright (c) 2012 Daniele Bartolini, Simone Boscaratto
#
# Permission is hereby granted, free of charge, to any person
# obtaining a copy of this software and associated documentation
# files (the "Software"), to deal in the Software without
# restriction, including without limitation the rights to use,
# copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following
# conditions:
# 
# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
# OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
# HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
# WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
# OTHER DEALINGS IN THE SOFTWARE.

import os

TEXTURE_EXTENSION			= ('.tga')
TEXT_EXTENSION				= ('.txt')
MESH_EXTENSION				= ('.dae')
LUA_EXTENSION				= ('.lua')
VERTEX_SHADER_EXTENSION		= ('.vs')
PIXEL_SHADER_EXTENSION		= ('.ps')

resource_extensions = ('.txt', '.tga', '.dae', '.lua', '.vs', '.ps')

# Represents the folder containing the resources
# Can filter resources by type and other useful stuff
class Repository:
	def __init__(self, root_path):
		self.m_resources = []
		self.set_root_path(root_path)

	# Sets the root path triggering a complete project scan()
	def set_root_path(self, root_path):
		self.m_root_path = root_path
		self.scan()

	# Returns the root path
	def root_path(self):
		return self.m_root_path

	# Returns a list of all the resources found
	def all_resources(self):
		return self.m_resources

	# Returns a list of all the texture resources found
	def texture_resources(self):
		textures = []

		for res in self.m_resources:
			if (res.endswith(TEXTURE_EXTENSION)):
				textures.append(res)

		return textures

	# Returns a list of all the text resources found
	def text_resources(self):
		texts = []

		for res in self.m_resources:
			if (res.endswith(TEXT_EXTENSION)):
				texts.append(res)

		return texts

	# Returns a list of all the mesh resources found
	def mesh_resources(self):
		meshes = []

		for res in self.m_resources:
			if (res.endswith(MESH_EXTENSION)):
				meshes.append(res)

		return meshes

	# Returns a list of all the lua resources found
	def script_resources(self):
		scripts = []

		for res in self.m_resources:
			if (res.endswith(LUA_EXTENSION)):
				scripts.append(res)

		return scripts

	# Returns a list of all the vertex shader resources found
	def vertex_shader_resources(self):
		vss = []

		for res in self.m_resources:
			if (res.endswith(VERTEX_SHADER_EXTENSION)):
				vss.append(res)

		return vss

	# Returns a list of all the pixel shader resources found
	def pixel_shader_resources(self):
		pss = []

		for res in self.m_resources:
			if (res.endswith(PIXEL_SHADER_EXTENSION)):
				pss.append(res)

		return pss

	# Scans the root path to find resources
	def scan(self):
		# Clear the resources
		self.m_resources = []

		for dirname, dirnames, filenames in os.walk(self.m_root_path):
			for filename in filenames:
				# Get the resource name
				abs_path = os.path.join(dirname, filename)
				resource_name = os.path.relpath(abs_path, self.m_root_path)

				# Normalize resource name, OSs != Windows/Linux may need
				# additional processing
				resource_name = resource_name.replace("\\", "/")

				# Filter resource names by type
				if resource_name.endswith(resource_extensions):
					self.m_resources.append(resource_name)

