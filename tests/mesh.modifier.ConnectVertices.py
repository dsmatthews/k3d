#python

import k3d
import testing

setup = testing.setup_mesh_modifier_test("PolyCube", "ConnectVertices")

selection = k3d.selection.set()
point_selection = k3d.geometry.point_selection.create(selection)
k3d.geometry.point_selection.append(point_selection, 0, 1, 1)
k3d.geometry.point_selection.append(point_selection, 2, 3, 1)

setup.modifier.mesh_selection = selection

testing.mesh_comparison_to_reference(setup.document, setup.modifier.get_property("output_mesh"), "mesh.modifier.ConnectVertices", 1)
