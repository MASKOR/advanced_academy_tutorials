from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='turtlesim',
            node_namespace='turtlesim1',
            node_executable='turtlesim_node',
			output= 'screen',
            node_name='sim'
        ),
		Node(
            package='academy_tools',
            node_namespace='academy_tools1',
            node_executable='academy_tools_talker',
			output= 'screen',
            node_name='sim'
        ),
		Node(
            package='academy_py',
            node_namespace='academy_py1',
            node_executable='service',
			output= 'screen',
            node_name='sim'
        )
    ])
