import React, { useState, useEffect } from "react";
import { useTheme } from "@react-navigation/native";
import { View, Text, TextInput, TouchableOpacity, StyleSheet} from "react-native";
import Icon from 'react-native-vector-icons/Octicons';
import IconEntypo from 'react-native-vector-icons/Entypo';
import IconMaterialIcons from 'react-native-vector-icons/MaterialIcons';
import AsyncStorage from '@react-native-async-storage/async-storage';
import { t } from "../Translate";

const Todolist = () => {
    const [task, setTask] = useState("");
    const [tasks, setTasks] = useState([]);
    const [editIndex, setEditIndex] = useState(-1);
    const { colors } = useTheme();

    const sendItem = async (data) => {
        const jsonValue = JSON.stringify(data);
        await AsyncStorage.setItem('todolist', jsonValue);
    }

    const getItem = async () => {
        let jsonData = await AsyncStorage.getItem('todolist');
        return (jsonData != null ? JSON.parse(jsonData) : []);;
    }

    const handleAddTask = async () => {
        if (task) {
            let tasksSave = await getItem();
            if (editIndex !== -1) {
                const updatedTasks = [...tasksSave];
                updatedTasks[editIndex] = task;
                await sendItem(updatedTasks);
                setTasks(updatedTasks);
                setEditIndex(-1);
            } else {
                await sendItem([...tasksSave, task]);
                setTasks([...tasksSave, task]);
            }
            setTask("");
        }
    };

    const handleEditTask = (index) => {
        const taskToEdit = tasks[index];
        setTask(taskToEdit);
        setEditIndex(index);
    };

    const handleDeleteTask = async (index) => {
        let tasksSave = await getItem();
        const updatedTasks = [...tasksSave];
        updatedTasks.splice(index, 1);
        await sendItem(updatedTasks);
        setTasks(updatedTasks);
        setEditIndex(-1);
        setTask("");
    };

    useEffect(() => {
        async function fetchTasks() {
            const tasksFromStorage = await getItem();
            setTasks(tasksFromStorage);
        }

        fetchTasks();
    }, []);

    const renderItem = ({ item, index }) => (
        <View key={index} style={styles.task}>
            <View style={{ flex: 1 }}>
                <Text style={[styles.itemList, { color: colors.text }]}>{item}</Text>
            </View>
            <View style={styles.taskButtons}>
                <TouchableOpacity onPress={() => handleEditTask(index)}>
                    <Text style={styles.editButton}>{t('edit')}</Text>
                </TouchableOpacity>
                <TouchableOpacity onPress={() => handleDeleteTask(index)}>
                    <Text style={styles.deleteButton}>{t('delete')}</Text>
                </TouchableOpacity>
            </View>
        </View>
    );

    return (
        <View style={[styles.container, { backgroundColor: colors.card }]}>
            <Text style={[styles.title, { color: colors.primary }]}>
                <Icon name="checklist" size={20} color={colors.primary} /> {t('todo').toUpperCase()}
            </Text>
            <View style={styles.inputContainer}>
                <TextInput
                    style={[styles.input, { borderColor: colors.border, color: colors.text, flex: 1 }]}
                    placeholder={t('enter task')}
                    value={task}
                    placeholderTextColor={colors.border}
                    onChangeText={(text) => setTask(text)}
                />
                <TouchableOpacity
                    style={[styles.addButton, { backgroundColor: colors.primary }]}
                    onPress={handleAddTask}
                >
                    {editIndex !== -1 ? (
                        <IconMaterialIcons style={styles.addButtonText} name="find-replace" color="white" />
                    ) : (
                        <IconEntypo style={styles.addButtonText} name="add-to-list" color="white" />
                    )}
                </TouchableOpacity>
            </View>
            {tasks.map((task, index) => {
                return renderItem({ item: task, index: index });
            })}
        </View>
    );
};

const styles = StyleSheet.create({
    container: {
        flex: 1,
        paddingHorizontal: 20,
        paddingTop: 20,
        paddingBottom: 5,
        borderRadius: 12,
    },
    title: {
        fontSize: 18,
        fontWeight: "bold",
        marginBottom: 20,
    },
    input: {
        borderWidth: 3,
        padding: 8,
        marginBottom: 10,
        borderRadius: 10,
        fontSize: 18,
    },
    inputContainer: {
        flexDirection: "row",
        alignItems: "center",
    },
    addButton: {
        padding: 8,
        borderRadius: 5,
        marginBottom: 10,
        marginLeft: 10,
        marginRight: -10,

    },
    addButtonText: {
        color: "white",
        fontWeight: "bold",
        textAlign: "center",
        fontSize: 26,
    },
    task: {
        flexDirection: "row",
        justifyContent: "space-between",
        alignItems: "center",
        marginBottom: 15,
        fontSize: 18,
    },
    itemList: {
        fontSize: 19,
    },
    taskButtons: {
        flexDirection: "row",
    },
    editButton: {
        marginRight: 10,
        color: "#34c759",
        fontWeight: "bold",
        fontSize: 18,
    },
    deleteButton: {
        color: "#ff3b30",
        fontWeight: "bold",
        fontSize: 18,
    },
});

export default Todolist;
